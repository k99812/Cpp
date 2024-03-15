#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

#define INF 1e9

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int t, h, w, dist[3][104][104];
char m[104][104];
string s;
vector<pair<int, int>> sinner;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int idx,const pair<int, int>& start)
{
	dist[idx][start.first][start.second] = 0;
	pq.push({ 0, start.first * 1000 + start.second });

	while (pq.size())
	{
		int here_y = pq.top().second / 1000, here_x = pq.top().second % 1000;
		int here_dist = pq.top().first; pq.pop();

		if (here_dist != dist[idx][here_y][here_x]) continue;

		for (int i = 0; i < 4; i++)
		{
			int ny = here_y + dy[i], nx = here_x + dx[i];
			int next_dist = m[ny][nx] == '#' ? 1 : 0;

			if (ny < 0 || nx < 0 || ny > h + 1 || nx > w + 1) continue;
			if (m[ny][nx] == '*') continue;

			if (dist[idx][ny][nx] > dist[idx][here_y][here_x] + next_dist)
			{
				dist[idx][ny][nx] = dist[idx][here_y][here_x] + next_dist;
				pq.push({ dist[idx][ny][nx], ny * 1000 + nx });
			}
		}
	}
}

void show()
{
	cout << "\n";
	for (int k = 0; k < 3; k++)
	{
		for (int i = 0; i <= h + 1; i++)
		{
			for (int j = 0; j <= w + 1; j++)
			{
				if (m[i][j] == '*')
				{
					cout << "  ";
					continue;
				}
				cout << dist[k][i][j] << " ";
			}
			cout << "\n";
		}
	}
}

int main()
{
	cin >> t;

	while (t--)
	{
		cin >> h >> w;
		fill(&m[0][0], &m[103][104], '.');
		fill(&dist[0][0][0], &dist[2][103][104], INF);

		for (int i = 1; i <= h; i++)
		{
			cin >> s;
			for(int j = 0; j < w; j++)
			{
				if (s[j] == '$')
				{
					sinner.push_back({ i, j + 1 });
				}
				m[i][j + 1] = s[j];
			}
		}

		dijkstra(0, {0, 0});
		dijkstra(1, sinner[0]);
		dijkstra(2, sinner[1]);

		//show();

		int minOpen = INF;
		int openDoor;

		for (int i = 0; i <= h + 1; i++)
		{
			for (int j = 0; j <= w + 1; j++)
			{
				if (m[i][j] == '*')
				{
					cout << "  ";
					continue;
				}

				openDoor = dist[0][i][j] + dist[1][i][j] + dist[2][i][j];

				if (m[i][j] == '#')
				{
					openDoor -= 2;
				}
				minOpen = min(minOpen, openDoor);
			}
		}
		
		cout << minOpen << "\n";
	}

	return 0;
}