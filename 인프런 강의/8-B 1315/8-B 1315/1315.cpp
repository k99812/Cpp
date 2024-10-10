#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

struct Stat
{
	int STR,
		INT,
		PNT;
};

int n, dp[1004][1004];
bool visited[54];
Stat q[54];

int go(int STR, int INT)
{
	int& ret = dp[STR][INT];
	if (ret != -1) return ret;

	ret = 0;
	int pnt = 0;
	vector<int> v;

	for (int i = 0; i < n; i++) 
	{
		if (q[i].STR <= STR || q[i].INT <= INT) 
		{
			ret++;
			if (!visited[i]) 
			{
				visited[i] = true;
				pnt += q[i].PNT;
				v.push_back(i);
			}
		}
	}

	for (int p = 0; p <= pnt; p++)
	{
		int next_STR = min(1000, STR + p);
		int next_INT = min(1000, INT + pnt - p);
		ret = max(ret, go(next_STR, next_INT));
	}

	for (int i : v)
	{
		visited[i] = false;
	}
	
	return ret;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> q[i].STR >> q[i].INT >> q[i].PNT;
	}

	fill(&dp[0][0], &dp[1003][1004], -1);

	cout << go(1, 1) << "\n";

	return 0;
}