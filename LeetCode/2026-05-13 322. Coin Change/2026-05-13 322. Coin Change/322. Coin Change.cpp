#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    const int INF = 1e9;

    int target;
    vector<int> coins;

public:
    Solution() : target(0)
    {

    }

    int coinChange(vector<int>& input, int amount) 
    {
        coins = input;
        target = amount;

        vector<int> dp(amount + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < input.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                if (dp[j - coins[i]] == INF) continue;

                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }

        return dp[amount] == INF ? -1 : dp[amount];
    }
};

int main()
{
    int amount = 11;
    vector<int> coins = { 1, 2, 5 };

    Solution sol = Solution();


    return 0;
}