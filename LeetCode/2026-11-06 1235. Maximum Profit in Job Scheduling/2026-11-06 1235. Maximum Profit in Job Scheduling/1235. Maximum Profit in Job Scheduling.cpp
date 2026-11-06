#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    struct Node
    {
        int start, end, cost;

        bool operator<(const Node& other) const
        {
            return start < other.start;
        }
    };

    int n;
    vector<Node> v;
    vector<int> start, dp;

    int dfs(int idx)
    {
        if (idx >= n) return 0;

        int& ret = dp[idx];
        if (ret != -1) return ret;

        ret = 0;

        ret = max(ret, dfs(idx + 1));

        int next = lower_bound(start.begin() + idx + 1, start.end(), v[idx].end) - start.begin();
        ret = max(ret, v[idx].cost + dfs(next));

        return ret;
    }

public:
    Solution() : n(0) {}

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        n = startTime.size();
        v.assign(n, {});
        dp.assign(n, -1);
        start.assign(n, 0);

        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += profit[i];
            v[i] = { startTime[i], endTime[i], profit[i] };
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++)
        {
            start[i] = v[i].start;
        }

        return dfs(0);
    }
};

int main()
{

    return 0;
}