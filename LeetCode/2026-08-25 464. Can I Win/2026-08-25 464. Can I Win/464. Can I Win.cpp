#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution
{
    int n, end;
    vector<int> dp;

    int dfs(int used, int sum)
    {
        int& ret = dp[used];
        if (ret != -1) return ret;

        ret = 0;

        for (int i = 1; i <= n; i++)
        {
            if (used & (1 << i)) continue;

            if (sum + i >= end) return ret = 1;

            if (dfs(used | (1 << i), sum + i) == 0) return ret = 1;
        }

        return ret = 0;
    }

public:
    Solution() : n(0), end(0)
    {

    }

    bool canIWin(int maxChoosableInteger, int desiredTotal)
    {
        n = maxChoosableInteger, end = desiredTotal;

        if (end <= 0) return true;

        int sum = (n * (n + 1)) / 2;
        if (sum < end) return false;

        dp.assign((1 << n + 1), -1);

        return dfs(0, 0);
    }
};

int main()
{

    return 0;
}