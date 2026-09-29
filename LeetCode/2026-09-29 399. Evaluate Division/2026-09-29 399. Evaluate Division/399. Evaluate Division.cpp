#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution 
{
    unordered_map<string, vector<pair<string, double>>> graph;

    double bfs(const string& start, const string& end)
    {
        if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) return -1.0;

        queue<pair<string, double>> q;
        unordered_set<string> visited;

        q.push({ start, 1.0 });
        visited.insert(start);

        while (q.size())
        {
            auto [now, now_cost] = q.front();
            q.pop();

            if (now == end) return now_cost;

            for (const auto& [next, next_cost] : graph[now])
            {
                if (visited.find(next) != visited.end()) continue;

                q.push({ next, now_cost * next_cost });
                visited.insert(next);
            }
        }

        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, 
        vector<vector<string>>& queries) 
    {
        for (int i = 0; i < equations.size(); i++)
        {
            string u = equations[i][0], v = equations[i][1];
            double value = values[i];

            graph[u].push_back({ v, value });
            graph[v].push_back({ u, 1.0 / value });
        }

        vector<double> ret;
        for (const vector<string>& query : queries)
        {
            string start = query[0], end = query[1];
            ret.push_back(bfs(start, end));
        }

        return ret;
    }
};

int main()
{

	return 0;
}