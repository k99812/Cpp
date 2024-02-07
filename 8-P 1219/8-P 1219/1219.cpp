#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int INF = -1e9;
int n, m, s, d, money[54], dist[54], x, y, z;
vector<pair<int, int>> grap[54];

int main()
{
	cin >> n >> s >> d >> m;

	

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> z;

		grap[x].push_back({ z, y });
	}

	for (int i = 0; i < n; i++)
	{
		cin >> money[i];
	}

	return 0;
}