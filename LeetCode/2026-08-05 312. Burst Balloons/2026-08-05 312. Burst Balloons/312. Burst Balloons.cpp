#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    int n;
    vector<int> num;
    vector<vector<int>> dp;

    int dfs(int left, int right)
    {
        if (left > right) return 0;

        int& ret = dp[left][right];
        if (ret != -1) return ret;

        ret = 0;

        for (int k = left; k <= right; k++)
        {
            int last = num[left - 1] * num[k] * num[right + 1];

            ret = max(ret, dfs(left, k - 1) + dfs(k + 1, right) + last);
        }

        return ret;
    }

public:
    Solution() : n(0)
    {

    }

    int maxCoins(vector<int>& nums) 
    {
        n = nums.size();

        num.assign(n + 2, 1);
        for (int i = 0; i < n; i++)
        {
            num[i + 1] = nums[i];
        }

        dp.assign(n + 2, vector<int>(n + 2, -1));

        return dfs(1, n);
    }
};

int main()
{

	return 0;
}