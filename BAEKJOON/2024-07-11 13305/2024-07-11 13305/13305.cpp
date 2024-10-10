#include<iostream>
#include<algorithm>

#define MAX_NUM 100004
#define INF 1e9

using namespace std;

typedef long long ll;

int n, dist[MAX_NUM], price[MAX_NUM];
ll ret;

int main()
{
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		cin >> dist[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> price[i];
	}

	int min_cost = INF;

	for (int i = 0; i < n; i++)
	{
		if (price[i] < min_cost) min_cost = price[i];
		ret += (ll)min_cost * dist[i];
	}

	cout << ret << "\n";

	return 0;
}