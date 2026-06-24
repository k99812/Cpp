#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct INFO
{
    int from, to, cost;

    bool operator<(const INFO& other) const
    {
        return cost < other.cost;
    }
};

class Solution 
{
    int n;
    vector<int> parents;

    int getRoot(int num)
    {
        if (parents[num] == num) return num;
        return parents[num] = getRoot(parents[num]);
    }

    void unionParent(int a, int b)
    {
        int parent_a = getRoot(a), parent_b = getRoot(b);

        if (parent_a != parent_b)
        {
            if (parent_a > parent_b) swap(parent_a, parent_b);

            parents[parent_b] = parent_a;
        }
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        n = points.size();
        parents.assign(n, 0);

        for (int i = 0; i < n; i++)
        {
            parents[i] = i;
        }

        vector<INFO> edges;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (i == j) continue;

                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int cost = abs(x1 - x2) + abs(y1 - y2);

                edges.push_back({ i, j, cost });
            }
        }

        sort(edges.begin(), edges.end());

        int ret = 0;
        for (const INFO& edge : edges)
        {
            if (getRoot(edge.from) != getRoot(edge.to))
            {
                ret += edge.cost;
                unionParent(edge.from, edge.to);
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}