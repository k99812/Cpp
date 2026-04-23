#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int t, n;
vector<pair<int, int>> cordi;
pair<int, int> home, rock;

int getDist(const pair<int, int>& a, const pair<int, int>& b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

bool bfs()
{
	queue<int> q;
	vector<int> visited(cordi.size());

	q.push(0);
	visited[0] = true;

	while (q.size())
	{
		pair<int, int> now = cordi[q.front()];
		q.pop();

		if (now == rock) return true;

		for (int i = 0; i < cordi.size(); i++)
		{
			if (visited[i]) continue;

			pair<int, int> next = cordi[i];

			if (getDist(now, next) <= 1000)
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}

	return false;
}

int main()
{
	cin >> t;

	while (t--)
	{
		cin >> n >> home.first >> home.second;

		cordi.clear();
		cordi.push_back(home);

		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			cordi.push_back({ x,y });
		}

		cin >> rock.first >> rock.second;

		cordi.push_back(rock);

		cout << (bfs() ? "happy" : "sad") << "\n";
	}

	return 0;
}