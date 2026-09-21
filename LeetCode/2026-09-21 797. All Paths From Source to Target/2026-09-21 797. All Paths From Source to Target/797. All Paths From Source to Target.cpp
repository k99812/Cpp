#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    int n;
    vector<vector<int>> graph, ret;

    void dfs(int now, vector<int>& path)
    {
        if (now == n - 1)
        {
            ret.push_back(path);
            return;
        }

        for (const int next : graph[now])
        {
            path.push_back(next);  

            dfs(next, path); 

            path.pop_back();     
        }
    }

public:
    Solution() : n(0)
    {

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        n = graph.size();
        this->graph = move(graph);

        vector<int> path;
        path.push_back(0);
        
        dfs(0, path);

        return ret;
    }
};

int main()
{

	return 0;
}