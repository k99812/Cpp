#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

class Solution 
{
    const int INF = INT_MAX;
    const int MOD = 1e9 + 7;

    int n;
    vector<vector<int>> dp;

    int dfs(int now, int fuel, int finish, vector<int>& lo)
    {
        if (fuel < 0) return 0;
        
        int& ret = dp[now][fuel];
        if (ret != -1) return ret;

        ret = (now == finish) ? 1 : 0;

        for (int i = 0; i < n; i++)
        {
            if (now == i) continue;

            int consum = abs(lo[now] - lo[i]);
            ret = (ret + dfs(i, fuel - consum, finish, lo)) % MOD;
        }

        return ret;
    }

public:
    Solution() : n(0) {}

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) 
    {
        n = locations.size();
        dp.assign(n, vector<int>(fuel + 1, -1));

        return dfs(start, fuel, finish, locations);
    }
};

int main()
{

	return 0;
}