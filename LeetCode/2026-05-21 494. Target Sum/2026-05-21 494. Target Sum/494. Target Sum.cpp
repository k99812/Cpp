#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    const int OFFSET = 1000;

    int n, t;
    vector<int> nums;
    vector<vector<int>> dp;

    int dfs(int idx, int sum)
    {
        if (idx == n) return sum == t ? 1 : 0;

        int& ret = dp[idx][sum + OFFSET];
        if (ret != -1) return ret;

        ret = 0;

        ret += dfs(idx + 1, sum + nums[idx]);
        ret += dfs(idx + 1, sum - nums[idx]);

        return ret;
    }

public:
    Solution() : n(0), t(0)
    {

    }

    int findTargetSumWays(vector<int>& input, int target) 
    {
        nums = move(input);
        n = nums.size(), t = target;

        dp.assign(n, vector<int>(2001, -1));

        return dfs(0, 0);
    }
};

int main()
{
    vector<int> nums = { 1,1,1,1,1 };
    int target = 3;

    Solution sol = Solution();
    cout << sol.findTargetSumWays(nums, target) << "\n";

    return 0;
}