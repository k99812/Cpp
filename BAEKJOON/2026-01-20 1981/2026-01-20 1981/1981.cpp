#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int INF = 1e9;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n;
vector<vector<int>> board;

int bfs(int min_val, int max_val)
{
	if (max_val < board[0][0] || board[0][0] < min_val) return false;
	if (max_val < board[n - 1][n - 1] || board[n - 1][n - 1] < min_val) return false;

	queue<pair<int, int>> q;
	vector<vector<int>> visited(n, vector<int>(n, 0));
	visited[0][0] = true;
	q.push({ 0, 0 });

	while (q.size())
	{
		int y = q.front().first, x = q.front().second;
		q.pop();

		if (y == n - 1 && x == n - 1) return true;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (visited[ny][nx]) continue;
			
			if (min_val <= board[ny][nx] && board[ny][nx] <= max_val)
			{
				q.push({ ny, nx });
				visited[ny][nx] = true;
			}
		}
	}

	return false;
}

bool go(int mid)
{
	for (int i = 0; i <= 200; i++)
	{
		if (bfs(i, i + mid)) return true;
	}
	return false;
}

int main()
{
	cin >> n;

	board.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	int low = 0, high = 200, ret = 200;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (go(mid))
		{
			high = mid - 1;
			ret = mid;
		}
		else
		{
			low = mid + 1;
		}
	}

	cout << ret << "\n";

	return 0;
}