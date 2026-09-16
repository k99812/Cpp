#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    const int BUY = 1;

    int n;
    vector<int> prices;
    vector<vector<int>> dp;

    int dfs(int idx, int state)
    {
        if (idx >= n) return 0;

        int& ret = dp[idx][state];
        if (ret != -1) return ret;

        ret = 0;

        if (state == BUY)
        {
            ret = max(ret, dfs(idx + 1, state));
            ret = max(ret, prices[idx] + dfs(idx + 2, 0));
        }
        else
        {
            ret = max(ret, -prices[idx] + dfs(idx + 1, BUY));
            ret = max(ret, dfs(idx + 1, state));
        }

        return ret;
    }

public:
    Solution() : n(0)
    {

    }

    int maxProfit(vector<int>& prices) 
    {
        n = prices.size();
        this->prices = move(prices);
        dp.assign(n, vector<int>(2, -1));

        return dfs(0, 0);
    }
};

int main()
{

	return 0;
}