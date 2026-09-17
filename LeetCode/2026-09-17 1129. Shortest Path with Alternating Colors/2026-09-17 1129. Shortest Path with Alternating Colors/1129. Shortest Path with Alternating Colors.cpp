#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct Node
{
    int color, idx;
};

class Solution 
{
    const int BLUE = 0;
    const int RED = 1;

    int n;
    vector<vector<Node>> graph;

    vector<int> bfs()
    {
        queue<Node> q;
        vector<vector<int>> visited(n, vector<int>(2, -1));

        q.push({ BLUE, 0 });
        q.push({ RED, 0 });
        visited[0][BLUE] = visited[0][RED] = 0;

        while (q.size())
        {
            auto [color, now] = q.front();
            q.pop();

            for (const Node& node : graph[now])
            {
                if (node.color == color || visited[node.idx][node.color] != -1) continue;

                visited[node.idx][node.color] = visited[now][color] + 1;
                q.push({ node.color, node.idx });
            }
        }

        vector<int> ret(n, -1);

        for (int i = 0; i < n; i++)
        {
            int blue = visited[i][BLUE], red = visited[i][RED];

            if (blue != -1 && red != -1) ret[i] = min(blue, red);
            else if (blue != -1) ret[i] = blue;
            else if (red != -1) ret[i] = red;
        }

        return ret;
    }

public:
    Solution() : n(0)
    {

    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) 
    {
        this->n = n;
        graph.assign(n, vector<Node>());

        for (const vector<int>& red : redEdges)
        {
            graph[red[0]].push_back({ RED, red[1] });
        }

        for (const vector<int>& blue : blueEdges)
        {
            graph[blue[0]].push_back({ BLUE, blue[1] });
        }

        return bfs();
    }
};

int main()
{

	return 0;
}