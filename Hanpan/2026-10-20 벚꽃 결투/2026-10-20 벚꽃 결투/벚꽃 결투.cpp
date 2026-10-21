#include <iostream>
#include <sstream>
#include <string>

enum ActionType 
{
    WAIT,                       // 대기
    MOVE,                       // 이동
    JAB,                        // 찌르기
    SWEEP,                      // 휩쓸기
    DASH,                       // 돌진
    GUARD,                      // 받아내기
    BREAK,                      // 무너뜨리기
    BLINK                       // 순보
};
enum Direction { U, R, D, L, UR, DR, DL, UL };

struct Action 
{
    ActionType type;
    Direction direction;
};

struct Plan 
{
    Action first, second;        // 이번 턴에 선택할 두 행동
};

struct PlayerState 
{
    int r, c;                    // 행·열, 각각 1..7
    int hp, blessing;            // 체력·가호
    int cooldown[8];             // cooldown[JAB] == 0이면 찌르기 사용 가능
};

struct TurnState 
{
    int my_id;                   // 내 플레이어 번호: 1 또는 2
    int turn;                    // 이번 턴 번호: 1..60
    int remaining_ms;            // 남은 총 응답 시간, ms
    int objective_r, objective_c;// 영맥의 행·열, 각각 1..7
    PlayerState me, opponent;    // 위치·체력·가호는 입력, 쿨다운은 기본 코드가 추적
    Plan opponent_previous;     // 직전 턴의 상대 행동, 첫 턴에는 대기·대기
};

bool is_legal(const TurnState& state, Plan plan);

// ==================== 전략 작성 영역 ====================

bool is_objective(const TurnState& state, int r, int c)
{
    return (state.objective_r == r && state.objective_c == c);
}

Action move_to_objective(const TurnState& state, int r, int c)
{
    if (c < state.objective_c)
        return Action{ MOVE, R };
    else if (c > state.objective_c)
        return Action{ MOVE, L };
    else if (r < state.objective_r)
        return Action{ MOVE, D };
    else if (r > state.objective_r)
        return Action{ MOVE, U };

    return Action{ WAIT, U };
}

Plan choose_actions(const TurnState& state) 
{
    int r = state.me.r, c = state.me.c;

    Action first = { WAIT, U };     // 첫 행동
    Action second = { WAIT, U };    // 두 번째 행동

    Action first = move_to_objective(state, r, c);

    if (first.type == MOVE)
    {
        switch (first.direction)
        {
        case U: r--; break;
        case R: c++; break;
        case D: r++; break;
        case L: c--; break;
        default: break;
        }
    }

    Action second = move_to_objective(state, r, c);

    return Plan{ first, second };
}

// ==================== 기본 처리 · 수정 불필요 ====================

static const int ROW_DELTA[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };
static const int COL_DELTA[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
static const int COOLDOWN[8] = { 0, 0, 1, 2, 2, 2, 1, 2 };
static const char* DIRECTION_NAME[8] = { "U", "R", "D", "L", "UR", "DR", "DL", "UL" };

static bool inside(int r, int c) 
{
    return 1 <= r && r <= 7 && 1 <= c && c <= 7;
}

static void update_cooldown(PlayerState* player, Plan previous) 
{
    for (int type = JAB; type <= BLINK; type++) 
    {
        bool used = (int)previous.first.type == type || (int)previous.second.type == type;
        int old = player->cooldown[type];
        player->cooldown[type] = used ? COOLDOWN[type] : old > 0 ? old - 1 : 0;
    }
}

bool is_legal(const TurnState& state, Plan plan) 
{
    Action actions[2] = { plan.first, plan.second };
    for (int i = 0; i < 2; i++) 
    {
        Action a = actions[i];
        if ((int)a.type < 0 || (int)a.type > 7) return false;
        if (a.type == WAIT) continue;
        if ((int)a.direction < 0 || (int)a.direction >= (a.type == BLINK ? 8 : 4)) return false;
        if (a.type != MOVE && state.me.cooldown[a.type] > 0) return false;
    }
    if (plan.first.type == MOVE || plan.first.type == BLINK) 
    {
        int distance = plan.first.type == BLINK ? 2 : 1;
        int r = state.me.r + distance * ROW_DELTA[plan.first.direction];
        int c = state.me.c + distance * COL_DELTA[plan.first.direction];
        if (!inside(r, c)) return false;
    }
    return plan.second.type == WAIT || plan.second.type == MOVE
        || plan.second.type != plan.first.type;
}

namespace protocol 
{
    bool read_action(std::istream& input, Action& action) 
    {
        int type;
        if (!(input >> type) || type < 0 || type > 7) return false;
        action.type = static_cast<ActionType>(type);
        action.direction = U;
        if (type == WAIT) return true;
        std::string direction;
        if (!(input >> direction)) return false;
        for (int i = 0; i < (type == BLINK ? 8 : 4); i++) 
        {
            if (direction == DIRECTION_NAME[i]) 
            {
                action.direction = static_cast<Direction>(i);
                return true;
            }
        }
        return false;
    }

    std::string to_text(Action action) 
    {
        if (action.type == WAIT) return "0";
        return std::to_string(action.type) + " " + DIRECTION_NAME[action.direction];
    }

    int run() 
    {
        TurnState state{};
        Plan own_previous{ {WAIT, U}, {WAIT, U} };
        int next_turn = 1;
        bool initialized = false;
        std::string line;
        while (std::getline(std::cin, line)) 
        {
            std::istringstream input(line);
            std::string command, extra;
            input >> command;
            if (command.empty()) continue;
            if (command == "INIT") 
            {
                int r1, c1, r2, c2;
                if (!(input >> state.objective_r >> state.objective_c >> r1 >> c1 >> r2 >> c2)
                    || !inside(state.objective_r, state.objective_c)
                    || !inside(r1, c1) || !inside(r2, c2) || (r1 == r2 && c1 == c2)) return 1;
                initialized = true;
            }
            else if (command == "READY") 
            {
                std::string role;
                if (!initialized || !(input >> role) || (role != "FIRST" && role != "SECOND")) return 1;
                state.my_id = role == "FIRST" ? 1 : 2;
                std::cout << "OK" << std::endl;
            }
            else if (command == "TURN") 
            {
                if (!state.my_id || !(input >> state.remaining_ms >> state.turn)
                    || state.remaining_ms <= 0 || state.turn != next_turn++ || state.turn > 60) return 1;
                for (int id = 1; id <= 2; id++) 
                {
                    auto& p = id == state.my_id ? state.me : state.opponent;
                    if (!(input >> p.r >> p.c >> p.hp >> p.blessing) || !inside(p.r, p.c)
                        || p.hp < 1 || p.hp > 10 || p.blessing < 0 || p.blessing >= 10) return 1;
                }
                if (state.me.r == state.opponent.r && state.me.c == state.opponent.c) return 1;
                if (!read_action(input, state.opponent_previous.first) || !read_action(input, state.opponent_previous.second)) return 1;
                if (state.turn > 1) 
                {
                    update_cooldown(&state.me, own_previous);
                    update_cooldown(&state.opponent, state.opponent_previous);
                }
                Plan plan = choose_actions(state);
                if (!is_legal(state, plan)) return 1;
                own_previous = plan;
                std::cout << to_text(plan.first) << ' ' << to_text(plan.second) << std::endl;
            }
            else if (command == "FINISH") break;
            else return 1;
            if (input >> extra) return 1;
        }
        return 0;
    }
}

int main() 
{
    return protocol::run();
}