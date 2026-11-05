#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    int n;
    vector<int> dp;

    int dfs(int idx, vector<int>& nums)
    {
        if (idx >= n) return 1;

        int& ret = dp[idx];
        if (ret != -1) return ret;

        ret = 0;

        int now = nums[idx];
        if (idx + 1 < n && now == nums[idx + 1])
        {
            if (dfs(idx + 2, nums)) return ret = 1;

            if (idx + 2 < n && now == nums[idx + 2])
            {
                if (dfs(idx + 3, nums)) return ret = 1;
            }
        }

        if (idx + 2 < n && now == nums[idx + 1] - 1 && now == nums[idx + 2] - 2)
        {
            if (dfs(idx + 3, nums)) return ret = 1;
        }

        return ret;
    }

public:
    Solution() : n(0) {}

    bool validPartition(vector<int>& nums) 
    {
        n = nums.size();
        dp.assign(n, -1);

        return dfs(0, nums) ? true : false;
    }
};

int main()
{

	return 0;
}