#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<tuple>

using namespace std;

const int MAX = 300;
int n, m, x_1, y_1, x_2, y_2, visited[MAX + 4][MAX + 4], cnt = 0;
char map[MAX + 4][MAX + 4];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;
string s;
bool flage;
vector<pair<int, int>> fre;

void printMap()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void bfs(int y, int x)
{
    fill(&visited[0][0], &visited[MAX + 3][MAX + 4], 0);
    q.push({ y, x });
    visited[y][x] = 1;

    while (q.size())
    {
        int tx, ty;
        tie(ty, tx) = q.front(); q.pop();

        if (map[ty][tx] == '#')
        {
            flage = true;
            map[ty][tx] = 'X';
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = ty + dy[i], nx = tx + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (visited[ny][nx]) continue;
            if (map[ny][nx] == '1')
            {
                fre.push_back({ ny, nx });
                visited[ny][nx] = 1;
                continue;
            }
            visited[ny][nx] = 1; q.push({ ny, nx });
        }
    }
}

void OtoZ()
{
    for (pair<int, int> i : fre)
    {
        map[i.first][i.second] = '0';
    }
    fre.clear();
}

int main()
{
    cin >> n >> m >> y_1 >> x_1 >> y_2 >> x_2;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            map[i][j] = s[j];
        }
    }

    while (true)
    {
        bfs(y_1 - 1, x_1 - 1);
        cnt++;
        if (flage) break;
        OtoZ();
    }

    cout << cnt << "\n";

    return 0;
}