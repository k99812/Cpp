#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    const int MOD = 1e9 + 7;
    const int dx[3] = { 0, -1, 1 };

    int step, n;
    vector<vector<int>> dp;

    int dfs(int now, int s)
    {
        if (now < 0 || now >= n) return 0;
        if (s == step) return now == 0 ? 1 : 0;

        int& ret = dp[now][s];
        if (ret != -1) return ret;

        ret = 0;

        for (int i = 0; i < 3; i++)
        {
            ret = (ret + dfs(now + dx[i], s + 1)) % MOD;
        }

        return ret;
    }

public:
    Solution() : step(0), n(0) {}

    int numWays(int steps, int arrLen) 
    {
        step = steps;
        n = min(arrLen, steps / 2 + 1);

        dp.assign(n, vector<int>(step, -1));

        return dfs(0, 0);
    }
};

int main()
{

	return 0;
}