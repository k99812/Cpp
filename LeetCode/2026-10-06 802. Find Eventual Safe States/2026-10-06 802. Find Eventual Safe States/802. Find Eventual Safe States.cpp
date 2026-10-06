#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    vector<int> visited;

    bool dfs(int now, const vector<vector<int>>& graph)
    {
        if (visited[now] != 0) return visited[now] == 2;

        visited[now] = 1;

        for (const int next : graph[now])
        {
            if (!dfs(next, graph))
            {
                return false;
            }
        }

        visited[now] = 2;
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> path;
        
        visited.assign(n, 0);

        vector<int> ret;
        for (int i = 0; i < n; i++)
        {
            if (dfs(i, graph))
            {
                ret.push_back(i);
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}