#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    int n, k;
    vector<vector<double>> dp;

    double dfs(int idx, vector<int>& nums, int cnt)
    {
        if (idx >= n) return 0;
        if (cnt == k) return -1e9;

        double& ret = dp[idx][cnt];
        if (ret != -1.0) return ret;

        ret = 0;

        double sum = 0;
        for (int i = idx; i < n; i++)
        {
            sum += nums[i];
            ret = max(ret, sum / (i - idx + 1) + dfs(i + 1, nums, cnt + 1));
        }

        return ret;
    }

public:
    Solution() : n(0), k(0) {}

    double largestSumOfAverages(vector<int>& nums, int k) 
    {
        this->k = k;
        n = nums.size();
        dp.assign(n, vector<double>(k, -1.0));

        return dfs(0, nums, 0);
    }
};

int main()
{

	return 0;
}