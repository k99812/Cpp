#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

class Solution 
{
    unordered_map<string, vector<string>> graph;
    vector<string> ret;

    void dfs(const string& now)
    {
        while (graph[now].size())
        {
            string next = graph[now].back();
            graph[now].pop_back();
            dfs(next);
        }

        ret.push_back(now);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        for (const vector<string>& ticket : tickets)
        {
            graph[ticket[0]].push_back(ticket[1]);
        }

        for (auto& [from, next] : graph)
        {
            sort(next.begin(), next.end(), greater<string>());
        }

        dfs("JFK");

        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main()
{

	return 0;
}