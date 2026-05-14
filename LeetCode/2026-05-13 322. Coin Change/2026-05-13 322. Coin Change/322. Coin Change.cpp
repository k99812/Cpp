#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
private:
    const int INF = 1e9;

    int target;
    vector<int> coins, dp;

    int dfs(int remain)
    {
        if (remain < 0) return INF;

        if (remain == 0) return 0;

        int& ret = dp[remain];
        if (ret != -1) return ret;

        ret = INF;

        for (const int coin : coins)
        {
            int temp = dfs(remain - coin);

            if (temp != INF)
            {
                ret = min(ret, temp + 1);
            }
        }

        return ret;
    }

public:
    Solution() : target(0)
    {

    }

    int coinChange(vector<int>& input, int amount) 
    {
        coins = input;
        target = amount;

        dp.assign(amount + 1, -1);

        int ret = dfs(amount);
        return ret == INF ? -1 : ret;

        /*dp.assign(amount + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < input.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                if (dp[j - coins[i]] == INF) continue;

                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }

        return dp[amount] == INF ? -1 : dp[amount];*/
    }
};

int main()
{
    int amount = 11;
    vector<int> coins = { 1, 2, 5 };

    Solution sol = Solution();


    return 0;
}