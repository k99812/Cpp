#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    const int INF = 1e9;

    int n, d;
    vector<vector<int>> dp;

    int dfs(int idx, int day, vector<int>& job)
    {
        if (idx == n && day == d) return 0;
        if (idx >= n || day >= d) return INF;

        int& ret = dp[idx][day];
        if (ret != -1) return ret;

        ret = INF;

        int max_num = 0;
        for (int i = idx; i < n && (day + n - i) >= d; i++)
        {
            max_num = max(max_num, job[i]);
            ret = min(ret, max_num + dfs(i + 1, day + 1, job));
        }

        return ret;
    }

public:
    Solution() : n(0), d(0) {}

    int minDifficulty(vector<int>& jobDifficulty, int d) 
    {
        this->d = d;
        n = jobDifficulty.size();
        if (d > n) return -1;

        dp.assign(n, vector<int>(d, -1));

        return dfs(0, 0, jobDifficulty);
    }
};

int main()
{

	return 0;
}