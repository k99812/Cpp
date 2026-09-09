#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    int n;
    vector<int> arr;
    vector<vector<int>> dp;

    int dfs(int idx, int m)
    {
        if (idx >= n) return 0;

        if (idx + 2 * m >= n) return arr[idx];

        int& ret = dp[idx][m];
        if (ret != -1) return ret;

        ret = 0;

        for (int i = 1; i <= 2 * m; i++)
        {
            ret = max(ret, arr[idx] - dfs(idx + i, max(m, i)));
        }

        return ret;
    }

public:
    Solution() : n(0)
    {

    }

    int stoneGameII(vector<int>& piles) 
    {
        n = piles.size();
        dp.assign(n, vector<int>(n + 1, -1));
        arr.assign(n, 0);

        arr[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            arr[i] = arr[i + 1] + piles[i];
        }

        return dfs(0, 1);
    }
};

int main()
{

	return 0;
}