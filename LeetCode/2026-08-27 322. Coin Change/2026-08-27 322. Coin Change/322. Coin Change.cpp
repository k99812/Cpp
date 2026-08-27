#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution
{
    const int INF = 1e9;

    vector<int> dp;

public:
    int coinChange(vector<int>& coins, int amount)
    {
        dp.assign(amount + 1, INF);

        dp[0] = 0;

        for (const int coin : coins)
        {
            for (int idx = coin; idx <= amount; idx++)
            {
                dp[idx] = min(dp[idx], dp[idx - coin] + 1);
            }
        }

        return dp[amount] == INF ? -1 : dp[amount];
    }
};

int main()
{

    return 0;
}