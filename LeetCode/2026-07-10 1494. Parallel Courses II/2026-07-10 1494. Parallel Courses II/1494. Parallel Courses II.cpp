#include<iostream>
#include<algorithm>
#include<vector>
#include<bit>

using namespace std;

class Solution 
{
    int n, k;
    vector<int> preReq, dp;

    int dfs(int bit)
    {
        if (bit == (1 << n) - 1) return 0;

        int& ret = dp[bit];
        if (ret != -1) return ret;

        int course = 0;
        for (int i = 0; i < n; i++)
        {
            if (!(bit & (1 << i)) && (bit & preReq[i]) == preReq[i])
            {
                course |= (1 << i);
            }
        }

        int bit_cnt = __builtin_popcount(course);
        ret = 1e9;

        if (bit_cnt <= k)
        {
            ret = 1 + dfs(bit | course);
        }
        else
        {
            for (int i = course; i > 0; i = (i - 1) & course)
            {
                if (__builtin_popcount(i) == k)
                {
                    ret = min(ret, 1 + dfs(bit | i));
                }
            }
        }

        return ret;
    }

public:
    Solution() : n(0), k(0)
    {

    }

    int minNumberOfSemesters(int N, vector<vector<int>>& relations, int K) 
    {
        n = N;
        k = K;
        preReq.assign(n, 0);
        dp.assign(1 << n, -1);

        for (const vector<int> edge : relations)
        {
            int prev = edge[0] - 1;
            int next = edge[1] - 1;
            preReq[next] |= (1 << prev);
        }

        return dfs(0);
    }
};

int main()
{

	return 0;
}