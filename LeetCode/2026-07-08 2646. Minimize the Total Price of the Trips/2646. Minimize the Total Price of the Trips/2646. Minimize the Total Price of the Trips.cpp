#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    const int INF = 1e9;

    int n;
    vector<int> price, visited_cnt;
    vector<vector<int>> graph, dp;

    bool dfs(int now, int parent, int target)
    {
        if (now == target)
        {
            visited_cnt[now]++;
            return true;
        }

        for (const int next : graph[now])
        {
            if (next == parent) continue;

            if (dfs(next, now, target))
            {
                visited_cnt[now]++;
                return true;
            }
        }

        return false;
    }

    int go(int now, int parent, bool isSale)
    {
        int& ret = dp[now][isSale];
        if (ret != -1) return ret;

        ret = isSale ? (price[now] / 2) * visited_cnt[now] : price[now] * visited_cnt[now];

        for (const int next : graph[now])
        {
            if (next == parent) continue;

            if (isSale)
            {
                ret += go(next, now, false);
            }
            else
            {
                ret += min(go(next, now, true), go(next, now, false));
            }
        }

        return ret;
    }

public:
    int minimumTotalPrice(int N, vector<vector<int>>& edges, vector<int>& InPrice, vector<vector<int>>& trips)
    {
        n = N;
        price = move(InPrice);
        visited_cnt.assign(n, 0);
        graph.assign(n, vector<int>());
        dp.assign(n, vector<int>(2, -1));

        for (const vector<int>& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for (const vector<int>& trip : trips)
        {
            dfs(trip[0], -1, trip[1]);
        }

        return min(go(0, -1, false), go(0, -1, true));
    }
};

int main()
{

	return 0;
}