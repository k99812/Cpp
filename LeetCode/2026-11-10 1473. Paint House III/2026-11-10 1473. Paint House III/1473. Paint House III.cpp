#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    const int INF = 1e9;

    int n, m, target;
    vector<vector<vector<int>>> dp;

    int dfs(int idx, int color, int cnt, vector<int>& houses, vector<vector<int>>& cost)
    {
        if (cnt > target) return INF;
        if (idx == n && cnt < target) return INF;
        if (idx >= n) return 0;

        int& ret = dp[idx][color][cnt];
        if (ret != -1) return ret;

        ret = INF;

        if (houses[idx])
        {
            int next_cnt = cnt + (houses[idx] != color ? 1 : 0);
            return ret = min(ret, dfs(idx + 1, houses[idx], next_cnt, houses, cost));
        }

        for (int i = 1; i <= m; i++)
        {
            int next_cnt = cnt + (i != color ? 1 : 0);
            ret = min(ret, cost[idx][i - 1] + dfs(idx + 1, i, next_cnt, houses, cost));
        }

        return ret;
    }

public:
    Solution() : n(0), m(0), target(0) {}

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) 
    {
        this->n = m;
        this->m = n;
        this->target = target;

        dp.assign(this->n, vector<vector<int>>(this->m + 1, vector<int>(target + 1, -1)));

        int ret = dfs(0, 0, 0, houses, cost);
        return ret == INF ? -1 : ret;
    }
};

int main()
{

	return 0;
}