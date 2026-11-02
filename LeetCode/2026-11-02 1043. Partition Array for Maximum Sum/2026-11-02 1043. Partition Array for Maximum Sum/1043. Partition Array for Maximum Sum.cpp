#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    int n, k;
    vector<int> arr, dp;

    int dfs(int idx)
    {
        if (idx >= n) return 0;

        int& ret = dp[idx];
        if (ret != -1) return ret;

        ret = 0;
        int max_num = 0;

        for (int i = idx; i < min(n, idx + k); i++)
        {
            max_num = max(max_num, arr[i]);
            int len = i - idx + 1;

            ret = max(ret, max_num * len + dfs(i + 1));
        }

        return ret;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        n = arr.size();
        this->k = k;
        this->arr = move(arr);
        dp.assign(n, -1);

        return dfs(0);
    }
};

int main()
{

	return 0;
}