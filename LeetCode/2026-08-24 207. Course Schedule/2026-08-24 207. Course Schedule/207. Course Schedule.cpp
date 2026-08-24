#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    vector<int> inDegree;
    vector<vector<int>> graph;

    bool topology(int n)
    {
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        int cnt = 0;

        while (q.size())
        {
            int now = q.front();
            q.pop();

            if (++cnt == n) return true;

            for (const int next : graph[now])
            {
                if (--inDegree[next] == 0)
                {
                    q.push(next);
                }
            }
        }

        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        inDegree.assign(numCourses, 0);
        graph.assign(numCourses, vector<int>());

        for (const vector<int>& v : prerequisites)
        {
            inDegree[v[0]]++;
            graph[v[1]].push_back(v[0]);
        }

        return topology(numCourses);
    }
};

int main()
{

	return 0;
}