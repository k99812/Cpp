#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

#define INF 1e9

using namespace std;

int n, t, visited[24];
vector<pair<int, int>> p;
double ret;

double length()
{
	pair<int, int> dot = { 0, 0 };

	for (int i = 0; i < n; i++)
	{
		if (visited[i])
		{
			dot.first -= p[i].first;
			dot.second -= p[i].second;
		}
		else
		{
			dot.first += p[i].first;
			dot.second += p[i].second;
		}
	}

	return sqrt(pow(dot.first, 2) + pow(dot.second, 2));
}

void dfs(int idx, int cnt)
{
	if (cnt == n / 2) 
	{
		ret = min(ret, length());
		return;
	}

	for (int i = idx; i < n; i++) {
		visited[i] = true;
		dfs(i + 1, cnt + 1);
		visited[i] = false; 
	}
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		fill(&visited[0], &visited[24], 0);
		p.clear();
		ret = INF;

		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			p.push_back({ a, b });
		}

		dfs(0, 0);

		cout << fixed;
		cout.precision(7);
		cout << ret << "\n";
	}

	return 0;
}