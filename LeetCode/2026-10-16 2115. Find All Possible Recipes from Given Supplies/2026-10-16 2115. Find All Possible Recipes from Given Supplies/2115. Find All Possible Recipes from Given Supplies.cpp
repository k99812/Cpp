#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution 
{
    int n;
    unordered_map<string, int> degree;
    unordered_map<string, vector<string>> graph;

    vector<string> bfs(vector<string>& supplies)
    {
        queue<string> q;
        vector<string> ret;

        for (const string& str : supplies)
        {
            q.push(str);
        }

        while (q.size())
        {
            string now = q.front();
            q.pop();

            for (const string& next : graph[now])
            {
                if (--degree[next] == 0)
                {
                    ret.push_back(next);
                    q.push(next);
                }
            }
        }

        return ret;
    }

public:
    Solution() : n(0) {}

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, 
        vector<string>& supplies) 
    {
        n = recipes.size();

        for (int i = 0; i < n; i++)
        {
            string now = recipes[i];
            for (const string& str : ingredients[i])
            {
                degree[now]++;
                graph[str].push_back(now);
            }
        }

        return bfs(supplies);
    }
};

int main()
{

	return 0;
}