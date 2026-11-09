#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution
{
    const int INF = 1e9;

    int n;
    vector<int> dp;

    int dfs(int idx, vector<int>& days, vector<int>& costs)
    {
        if (idx >= n) return 0;

        int& ret = dp[idx];
        if (ret != -1) return ret;

        ret = INF;

        int next7 = lower_bound(days.begin() + idx, days.end(), days[idx] + 7) - days.begin();
        int next30 = lower_bound(days.begin() + idx, days.end(), days[idx] + 30) - days.begin();

        int one = costs[0] + dfs(idx + 1, days, costs);
        int seven = costs[1] + dfs(next7, days, costs);
        int thirty = costs[2] + dfs(next30, days, costs);

        return ret = min({ ret, one, seven, thirty });
    }

public:
    Solution() : n(0) {}
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        n = days.size();
        dp.assign(n, -1);

        return dfs(0, days, costs);
    }
};

class Solution 
{
    const int INF = 1e9;

    int n;
    vector<vector<int>> dp;

    int dfs(int idx, int day, vector<int>& days, vector<int>& costs)
    {
        if (idx >= n) return 0;

        int& ret = dp[idx][day];
        if (ret != -1) return ret;

        ret = INF;

        if (day >= days[idx])
        {
            return ret = min(ret, dfs(idx + 1, day, days, costs));
        }

        int one = costs[0] + dfs(idx + 1, days[idx], days, costs);
        int seven = costs[1] + dfs(idx + 1, days[idx] + 7 - 1, days, costs);
        int thirty = costs[2] + dfs(idx + 1, days[idx] + 30 - 1, days, costs);

        return ret = min({ ret, one, seven, thirty });
    }

public:
    Solution() : n(0) {}
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        n = days.size();
        dp.assign(n, vector<int>(400, -1));

        return dfs(0, 0, days, costs);
    }
};

int main()
{

	return 0;
}