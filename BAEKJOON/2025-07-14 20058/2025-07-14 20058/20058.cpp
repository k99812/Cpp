#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int N, n, q;
vector<vector<int>> board, visited;

void go(int num)
{
	int sub_size = (1 << num);

	vector<vector<int>> temp(n, vector<int>(n));

	for (int sy = 0; sy < n; sy += sub_size)
	{
		for (int sx = 0; sx < n; sx += sub_size)
		{
			for (int i = 0; i < sub_size; i++)
			{
				for (int j = 0; j < sub_size; j++)
				{
					temp[sy + j][sx + sub_size - i - 1] = board[sy + i][sx + j];
				}
			}
		}
	}
	board = temp;

	vector<pair<int, int>> cordi;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!board[i][j]) continue;

			int cnt = 0;
			for (int dir = 0; dir < 4; dir++)
			{
				int ny = i + dy[dir], nx = j + dx[dir];
				if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
				if (!board[ny][nx]) continue;

				cnt++;
			}

			if (cnt < 3) cordi.push_back({ i, j });
		}
	}

	for (const pair<int, int>& itr : cordi)
	{
		board[itr.first][itr.second]--;
	}
}

int bfs(int y, int x)
{
	queue<pair<int, int>> q;
	visited[y][x] = true;
	q.push({ y, x });

	int cnt = 1;
	while (q.size())
	{
		int cy = q.front().first, cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i], nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (!board[ny][nx] || visited[ny][nx]) continue;

			cnt++;
			visited[ny][nx] = true;
			q.push({ ny, nx });
		}
	}

	return cnt;
}

int main()
{
	cin >> N >> q;

	n = (1 << N);

	board = visited = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < q; i++)
	{
		int l;
		cin >> l;

		go(l);
	}

	int sum = 0, max_cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum += board[i][j];
			
			if (!board[i][j] || visited[i][j]) continue;

			max_cnt = max(max_cnt, bfs(i, j));
		}
	}

	cout << sum << "\n" << max_cnt << "\n";

	return 0;
}