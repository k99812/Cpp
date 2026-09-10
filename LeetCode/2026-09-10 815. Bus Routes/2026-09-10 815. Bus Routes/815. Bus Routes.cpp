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
    unordered_map<int, vector<int>> un_map;

    int bfs(const int& s, const int& t, vector<vector<int>>& routes)
    {
        queue<int> q;
        unordered_set<int> visited_stops;
        vector<bool> visited_routes(n, false);

        q.push(s);
        visited_stops.insert(s);

        int cnt = 0;
        while (q.size())
        {
            int size = q.size();
            cnt++;

            while (size--)
            {
                int now = q.front();
                q.pop();

                for (const int next : un_map[now])
                {
                    if (visited_routes[next]) continue;
                    visited_routes[next] = true;

                    for (const int stop : routes[next])
                    {
                        if (visited_stops.find(stop) != visited_stops.end()) continue;
                        if (stop == t) return cnt;

                        visited_stops.insert(stop);
                        q.push(stop);
                    }
                }
            }
        }

        return -1;
    }

public:
    Solution() : n(0)
    {

    }

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) 
    {
        if (source == target) return 0;

        n = routes.size();

        for (int i = 0; i < n; i++)
        {
            for (const int stop : routes[i])
            {
                un_map[stop].push_back(i);
            }
        }

        return bfs(source, target, routes);
    }
};

int main()
{

	return 0;
}