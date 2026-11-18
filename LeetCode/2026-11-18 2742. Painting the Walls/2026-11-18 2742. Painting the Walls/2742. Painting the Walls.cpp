#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    const int INF = 1e9;

    int n;
    vector<vector<int>> dp;

    int dfs(int now, int re, vector<int>& cost, vector<int>& time)
    {
        if (re <= 0) return 0;
        if (now == n) return INF;

        int& ret = dp[now][re];
        if (ret != -1) return ret;

        ret = INF;

        ret = min(ret, dfs(now + 1, re, cost, time));
        ret = min(ret, cost[now] + dfs(now + 1, re - time[now] - 1, cost, time));

        return ret;
    }

public:
    Solution() : n(0) {}

    int paintWalls(vector<int>& cost, vector<int>& time) 
    {
        n = cost.size();
        dp.assign(n, vector<int>(n + 1, -1));

        return dfs(0, n, cost, time);
    }
};

int main()
{

	return 0;
}