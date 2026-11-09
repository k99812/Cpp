#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    int n, k;
    vector<int> start;
    vector<int> next_idx;
    vector<vector<int>> dp;

    int dfs(int idx, int cnt, vector<vector<int>>& events)
    {
        if (idx >= n || cnt == k) return 0;

        int& ret = dp[idx][cnt];
        if (ret != -1) return ret;

        ret = 0;

        int skip = dfs(idx + 1, cnt, events);
        int next = events[idx][2] + dfs(next_idx[idx], cnt + 1, events);

        return ret = max(skip, next);
    }

public:
    Solution() : n(0), k(0) {}

    int maxValue(vector<vector<int>>& events, int k) 
    {
        n = events.size();
        this->k = k;

        start.assign(n, 0);
        next_idx.assign(n, 0);
        dp.assign(n, vector<int>(k, -1));

        sort(events.begin(), events.end());

        for (int i = 0; i < n; i++)
        {
            start[i] = events[i][0];
        }

        for (int i = 0; i < n; i++)
        {
            next_idx[i] = lower_bound(start.begin() + i + 1, start.end(), events[i][1] + 1) - start.begin();
        }

        return dfs(0, 0, events);
    }
};

int main()
{

	return 0;
}