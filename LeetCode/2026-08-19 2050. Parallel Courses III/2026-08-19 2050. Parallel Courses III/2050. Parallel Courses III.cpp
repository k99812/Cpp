#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    int n;
    vector<int> inDegree, time, dp;
    vector<vector<int>> graph;

    int topology()
    {
        queue<int> q;

        for (int i = 1; i <= n; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
                dp[i] = time[i];
            }
        }

        while (q.size())
        {
            int now = q.front();
            q.pop();

            for (const int next : graph[now])
            {
                dp[next] = max(dp[next], dp[now] + time[next]);

                if (--inDegree[next] == 0)
                {
                    q.push(next);
                }
            }
        }

        int ret = 0;
        for (int i = 1; i <= n; i++)
        {
            ret = max(ret, dp[i]);
        }

        return ret;
    }

public:
    Solution() : n(0)
    {

    }

    int minimumTime(int N, vector<vector<int>>& relations, vector<int>& Time) 
    {
        n = N;
        time = { 0 };
        time.insert(time.end(), Time.begin(), Time.end());

        dp.assign(n + 1, 0);
        inDegree.assign(n + 1, 0);
        graph.assign(n + 1, vector<int>());

        for (const vector<int>& v : relations)
        {
            inDegree[v[1]]++;
            graph[v[0]].push_back(v[1]);
        }

        return topology();
    }
};

int main()
{

	return 0;
}