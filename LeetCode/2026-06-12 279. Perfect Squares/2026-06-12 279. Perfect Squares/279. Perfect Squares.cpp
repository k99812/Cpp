#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    const int INF = 1e9;

    int n;
    vector<int> dp;

    int dfs(int now)
    {
        if (now > n) return INF;

        if (now == n) return 0;

        int& ret = dp[now];
        if (ret != -1) return ret;

        ret = INF;

        for (int i = 1; now + i * i <= n; i++)
        {
            ret = min(ret, dfs(now + i * i) + 1);
        }

        return ret;
    }

public:
    Solution() : n(0)
    {

    }

    int numSquares(int num) 
    {
        n = num;
        dp.assign(n + 1, -1);

        return dfs(0);
    }
};

int main()
{
    int n = 12;
    Solution sol = Solution();

    cout << sol.numSquares(n) << "\n";

	return 0;
}