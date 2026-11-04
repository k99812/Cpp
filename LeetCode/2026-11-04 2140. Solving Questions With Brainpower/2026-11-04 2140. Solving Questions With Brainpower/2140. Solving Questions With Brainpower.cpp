#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    typedef long long ll;

    int n;
    vector<ll> dp;

    ll dfs(int idx, vector<vector<int>>& que)
    {
        if (idx >= n) return 0;

        ll& ret = dp[idx];
        if (ret != -1) return ret;

        ret = 0;

        ll skip = dfs(idx + 1, que);
        ll take = que[idx][0] + dfs(idx + que[idx][1] + 1, que);
        return ret = max(skip, take);
    }

public:
    Solution() : n(0) {}

    long long mostPoints(vector<vector<int>>& questions) 
    {
        n = questions.size();
        dp.assign(n, -1);

        return dfs(0, questions);
    }
};

int main()
{

	return 0;
}