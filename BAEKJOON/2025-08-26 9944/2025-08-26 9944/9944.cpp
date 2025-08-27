#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

const int INF = 1e9;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n, m, totalEmpty;
vector<vector<int>> board, visited;

int go(int y, int x, int visitedCnt)
{
	if (visitedCnt == totalEmpty) return 0;

	int ret = INF;

	for (int i = 0; i < 4; i++)
	{
		int ny = y, nx = x;
		vector<pair<int, int>> path;

		while (true)
		{
			ny = ny + dy[i], nx = nx + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) break;
			if (board[ny][nx] == 1 || visited[ny][nx]) break;
			visited[ny][nx] = true;
			path.push_back({ ny, nx });
		}

		if (path.size())
		{
			ret = min(ret, go(ny - dy[i], nx - dx[i], visitedCnt + path.size()) + 1);
			for (const pair<int, int>& p : path)
			{
				visited[p.first][p.second] = false;
			}
		}
	}

	return ret;
}

int main()
{
    int case_cnt = 1;
    while (cin >> n >> m)
    {
        board = vector<vector<int>>(n, vector<int>(m));
        totalEmpty = 0;

        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            for (int j = 0; j < m; j++)
            {
                if (str[j] == '*') board[i][j] = 1;
                else board[i][j] = 0, totalEmpty++;
            }
        }

        int ans = INF;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 0)
                {
                    visited = vector<vector<int>>(n, vector<int>(m, 0));
                    visited[i][j] = 1;
                    ans = min(ans, go(i, j, 1));
                }
            }
        }

        cout << "Case " << case_cnt++ << ": ";
        if (ans == INF) cout << -1 << "\n";
        else cout << ans << "\n";
    }
	
	return 0;
}