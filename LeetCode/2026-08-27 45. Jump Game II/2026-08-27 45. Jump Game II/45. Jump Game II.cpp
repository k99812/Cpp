#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    const int INF = 1e9;

    int n;
    vector<int> dp, arr;

    int dfs(int idx)
    {
        if (idx == n - 1) return 0;
        
        if (idx >= n) return INF;

        int& ret = dp[idx];
        if (ret != -1) return ret;

        ret = INF;

        for (int i = 1; i <= arr[idx]; i++)
        {
            ret = min(ret, 1 + dfs(idx + i));
        }

        return ret;
    }

public:
    int dp(vector<int>& nums) 
    {
        n = nums.size();
        arr = move(nums);

        dp.assign(n, -1);

        int ret = dfs(0);
        return ret == INF ? -1 : ret;
    }

    int jump(vector<int>& nums)
    {
        int n = nums.size();
        
        int cnt = 0, now_end = 0, max_dist = 0;

        for (int i = 0; i < n - 1; i++)
        {
            max_dist = max(max_dist, i + nums[i]);

            if (i == now_end)
            {
                cnt++;
                now_end = max_dist;

                if (now_end >= n - 1) break;
            }
        }

        return cnt;
    }
};

int main()
{

	return 0;
}