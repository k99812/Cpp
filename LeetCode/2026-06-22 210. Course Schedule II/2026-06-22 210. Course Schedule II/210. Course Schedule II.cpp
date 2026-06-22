#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    int n;
    vector<int> inDegree;
    vector<vector<int>> prerequisites, graph;

    vector<int> topology()
    {
        queue<int> q;
        vector<int> sequence;

        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (q.size())
        {
            int now = q.front();
            sequence.push_back(now);
            q.pop();

            for (const int next : graph[now])
            {
                if (--inDegree[next] == 0)
                {
                    q.push(next);
                }
            }
        }

        if (sequence.size() != n)
        {
            return vector<int>();
        }

        return sequence;
    }

public:
    Solution() : n(0)
    {

    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& input) 
    {
        n = numCourses;
        prerequisites = move(input);
        graph.assign(n, vector<int>());
        inDegree.assign(n, 0);

        for (const vector<int>& edge : prerequisites)
        {
            graph[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
        }

        return topology();
    }
};

int main()
{

	return 0;
}