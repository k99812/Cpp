#include<iostream>
#include<algorithm>

#define MAX_N 16
using namespace std;

const int INF = 1e9;
int n, a[MAX_N][MAX_N], dp[MAX_N][1 << MAX_N];

int tsp(int here, int visited)
{
	//탈출
	if (visited == (1 << n) - 1) return a[here][0] ? a[here][0] : INF;

	//메모리제이션
	int& ret = dp[here][visited];
	if (ret != -1 ) return ret;
	ret = INF;

	//로직
	for (int i = 0; i < n; i++)
	{
		if (visited & (1 << i)) continue;
		if (a[here][i] == 0) continue;
		ret = min(ret, tsp(i, visited | (1 << i)) + a[here][i]);
	}
	
	return ret;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	fill(&dp[0][0], &dp[MAX_N - 1][1 << MAX_N], -1);
	cout << tsp(0, 1) << "\n";

	return 0;
}