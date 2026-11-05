#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    int n, k;
    vector<vector<int>> dp;

    int dfs(int idx, int cnt, vector<vector<int>>& p)
    {
        if (cnt == k || idx >= n) return 0;

        int& ret = dp[idx][cnt];
        if (ret != -1) return ret;

        ret = dfs(idx + 1, cnt, p);

        int sum = 0;
        for (int i = 0; i < p[idx].size() && cnt + i + 1 <= k; i++)
        {
            sum += p[idx][i];
            ret = max(ret, sum + dfs(idx + 1, cnt + i + 1, p));
        }

        return ret;
    }

public:
    Solution() : n(0), k(0) {}

    int maxValueOfCoins(vector<vector<int>>& piles, int k) 
    {
        this->k = k;
        n = piles.size();
        dp.assign(n, vector<int>(k, -1));

        return dfs(0, 0, piles);
    }
};

int main()
{

	return 0;
}