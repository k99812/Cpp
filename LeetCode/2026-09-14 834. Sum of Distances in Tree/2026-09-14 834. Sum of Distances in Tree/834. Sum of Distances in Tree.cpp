#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    int n;
    vector<vector<int>> graph;
    vector<int> count, ret;

    void postDFS(int now, int parent)
    {
        for (const int next : graph[now])
        {
            if (next == parent) continue;

            postDFS(next, now);

            count[now] += count[next];
            ret[now] += ret[next] + count[next];
        }
    }

    void preDFS(int now, int parent)
    {
        for (const int next : graph[now])
        {
            if (next == parent) continue;

            ret[next] = ret[now] - count[next] + (n - count[next]);

            preDFS(next, now);
        }
    }

public:
    Solution() : n(0)
    {

    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) 
    {
        this->n = n;
        graph.assign(n, vector<int>());
        count.assign(n, 1);
        ret.assign(n, 0);

        for (const vector<int>& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        postDFS(0, -1);
        preDFS(0, -1);

        return ret;
    }
};

int main()
{

	return 0;
}