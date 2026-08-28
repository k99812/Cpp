#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    int n;
    vector<int> inDegree;
    vector<vector<int>> graph;

    vector<int> topology()
    {
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 1)
            {
                q.push(i);
            }
        }

        int nodes = n;

        while (nodes > 2)
        {
            int size = q.size();
            nodes -= size;

            while (size--)
            {
                int now = q.front();
                q.pop();

                for (const int next : graph[now])
                {
                    if (--inDegree[next] == 1)
                    {
                        q.push(next);
                    }
                }
            }
        }

        vector<int> ret;
        while (q.size())
        {
            ret.push_back(q.front());
            q.pop();
        }

        return ret;
    }

public:
    vector<int> findMinHeightTrees(int N, vector<vector<int>>& edges) 
    {
        if (N == 1) return { 0 };

        n = N;
        inDegree.assign(n, 0);
        graph.assign(n, vector<int>());

        for (const vector<int>& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
            inDegree[edge[1]]++;
        }
        
        return topology();
    }
};

int main()
{

	return 0;
}