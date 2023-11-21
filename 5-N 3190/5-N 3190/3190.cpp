#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

int n, k, l, y, x, a[104][104], visited[104][104], timer, t;
char c;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
vector<pair<int, int>> _time;
deque<pair<int, int>> dq;

void go(int y, int x)
{
	int idx = 0, dir = 1;
	dq.push_front({ y, x });

	while (dq.size())
	{
		timer++;
		tie(y, x) = dq.front();
		int ny = y + dy[dir], nx = x + dx[dir];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) break;
		if (visited[ny][nx]) break;

		if (!a[ny][nx])
		{
			visited[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
		}
		else a[ny][nx] = 0;

		visited[ny][nx] = 1;
		dq.push_front({ ny, nx });

		if (idx < l && timer == _time[idx].first)
		{
			dir = (dir + _time[idx].second) % 4;
			idx++;
		}
	}
}

int main()
{
	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> y >> x;
		a[--y][--x] = 1;
	}

	cin >> l;


	for (int i = 0; i < l; i++) 
	{
		cin >> t >> c;
		if (c == 'D') _time.push_back({ t, 1 });
		else _time.push_back({ t, 3 });
	}

	go(0, 0);

	cout << timer << "\n";

	return 0;
}