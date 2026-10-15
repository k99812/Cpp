#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    typedef long long ll;

    int n, m;
    vector<ll> dp;

    ll dfs(int idx, const vector<vector<int>>& rides)
    {
        if (idx >= m) return 0;

        ll& ret = dp[idx];
        if (ret != -1) return ret;

        auto itr = lower_bound(rides.begin() + idx + 1, rides.end(), rides[idx][1],
            [](const vector<int>& ride, int end)
        {
            return ride[0] < end;
        });

        int next_idx = distance(rides.begin(), itr);
        int cost = rides[idx][1] - rides[idx][0] + rides[idx][2];

        ret = max(ret, dfs(idx + 1, rides));
        ret = max(ret, cost + dfs(next_idx, rides));

        return ret;
    }

public:
    Solution() : n(0), m(0)
    {

    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) 
    {
        this->n = n;
        m = rides.size();
        dp.assign(m, -1);

        sort(rides.begin(), rides.end());

        return dfs(0, rides);
    }
};

int main()
{

	return 0;
}