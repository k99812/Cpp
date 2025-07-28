#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<map>

using namespace std;

struct Fish
{
	int y, x, d, ID;
};

struct comp
{
	bool operator()(const pair<int, string>& a, const pair<int, string>& b)
	{
		if (a.first != b.first) return a.first < b.first;
		return a.second > b.second;
	}
};

const int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
const int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int shark_dy[] = { -1, 0, 1, 0 };
const int shark_dx[] = { 0, -1, 0, 1 };
const int n = 4, INF = 1e9, SMELL = 1;

int m, s;
vector<vector<vector<int>>> board;
vector<Fish> fish;
map<int, bool> fish_alive;
vector<vector<pair<int, int>>> fish_smell;
pair<int, int> shark;

void move_shark(string s, int y, int x, int sum, vector<vector<int>> visited, priority_queue<pair<int, string>, vector<pair<int, string>>, comp>& pq )
{
	if (s.size() == 3)
	{
		pq.push({ sum, s });
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + shark_dy[i], nx = x + shark_dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

		int cost = visited[ny][nx] ? 0 : board[ny][nx].size();
		visited[ny][nx] = true;

		s.push_back(i + '0');
		move_shark(s, ny, nx, sum + cost, visited, pq);
		s.pop_back();
	}
}

void go()
{
	//try copy
	vector<Fish> copied_fish;
	for (int i = 0; i < fish.size(); i++)
	{
		if (!fish_alive[fish[i].ID]) continue;

		Fish f = fish[i];
		f.ID += i + m;

		copied_fish.push_back(f);
	}

	//fish move
	for (Fish& itr : fish)
	{
		const int id = itr.ID;
		if (!fish_alive[id]) continue;

		int& y = itr.y, x = itr.x, dir = itr.d;
		for (int i = 0; i < 8; i++)
		{
			int d = (dir - i + 8) % 8;
			int ny = y + dy[d], nx = x + dx[d];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (fish_smell[ny][nx].first > 0) continue;
			if (shark.first == ny && shark.second == nx) continue;

			for (int target = 0; target < board[y][x].size(); target++)
			{
				if (id != board[y][x][target]) continue;
				board[y][x].erase(board[y][x].begin() + target);
				break;
			}

			board[ny][nx].push_back(id);
			y = ny, x = nx, dir = d;

			break;
		}
	}

	//shark move
	priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
	vector<vector<int>> visited(n, vector<int>(n));
	visited[shark.first][shark.second] = true;

	move_shark("", shark.first, shark.second, 0, visited, pq);

	string s_move = pq.top().second;
	for (char dir : s_move)
	{
		int d = dir - '0';
		int ny = shark.first + shark_dy[d], nx = shark.second + shark_dx[d];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

		if (board[ny][nx].size())
		{
			for (const int& ID : board[ny][nx])
			{
				if (fish_alive[ID]) fish_alive[ID] = false;
			}

			fish_smell[ny][nx] = { SMELL, 3 };
			board[ny][nx].clear();
		}

		shark.first = ny, shark.second = nx;
	}

	//erase smell
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (fish_smell[i][j].second > 0 && --fish_smell[i][j].second == 0)
			{
				fish_smell[i][j] = { 0, 0 };
			}
		}
	}

	//copy
	for (const Fish& f : copied_fish)
	{
		fish.push_back(f);
		fish_alive[f.ID] = true;
		board[f.y][f.x].push_back(f.ID);
	}
}

int main()
{
	cin >> m >> s;

	board = vector<vector<vector<int>>>(n, vector<vector<int>>(n));
	fish = vector<Fish>(m);
	fish_smell = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(n));

	for (int i = 0; i < m; i++)
	{
		cin >> fish[i].x >> fish[i].y >> fish[i].d;
		fish[i].x--, fish[i].y--, fish[i].d--, fish[i].ID = i;

		fish_alive[fish[i].ID] = true;
		board[fish[i].y][fish[i].x].push_back(i);
	}

	cin >> shark.second >> shark.first;
	shark.first--, shark.second--;

	for (int i = 0; i < s; i++)
	{
		go();
	}

	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ret += board[i][j].size();
		}
	}

	cout << ret << "\n";

	return 0;
}