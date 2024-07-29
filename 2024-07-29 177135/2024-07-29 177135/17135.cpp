#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define MAX_NUM 15
#define cordi 1000

using namespace std;

int n, m, d, a[MAX_NUM][MAX_NUM], map[MAX_NUM][MAX_NUM], ret, arc[MAX_NUM];

int dist(const pair<int, int>& a, const pair<int, int>& b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void printMap()
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

int attack()
{
	int ans = 0;

	int archerRow = n;

	while (archerRow >= 1)
	{
		vector<pair<int, int>> target;

		for (int k = 0; k < m; k++)
		{
			if (!arc[k]) continue;

			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

			for (int i = 0; i < archerRow; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (!map[i][j]) continue;
					if (dist({n, k}, {i, j}) > d) continue;

					pq.push({ dist({n, k}, {i, j}), i * cordi + j });
				}
			}

			if (pq.size())
			{
				target.push_back({ pq.top().second / cordi, pq.top().second % cordi });
			}
		}

		for (const pair<int, int>& t : target)
		{
			if (map[t.first][t.second])
			{
				map[t.first][t.second] = 0;
				ans++;
			}
		}

		cout << " row : " << archerRow << "\n";
		printMap();

		archerRow--;
	}

	return ans;
}

void go(int idx, int num)
{
	if (idx == 3) 
	{
		copy(&a[0][0], &a[MAX_NUM - 1][MAX_NUM], &map[0][0]);
		ret = max(ret, attack());
		return;
	}
	for (int i = num; i < m; i++) 
	{
		arc[i] = true;
		go(idx + 1, i + 1);
		arc[i] = false;
	}
	return;
}

int main()
{
	cin >> n >> m >> d;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	go(0, 0);

	cout << ret << "\n";

	return 0;
}