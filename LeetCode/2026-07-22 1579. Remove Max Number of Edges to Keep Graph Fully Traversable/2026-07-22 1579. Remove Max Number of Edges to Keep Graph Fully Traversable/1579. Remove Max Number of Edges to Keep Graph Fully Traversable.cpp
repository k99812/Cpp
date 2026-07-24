#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct UnionFind
{
    vector<int> parents;
    int components;

    UnionFind(int n)
    {
        components = n;
        parents.assign(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            parents[i] = i;
        }
    }

    int getRoot(int num)
    {
        if (parents[num] == num) return num;
        return parents[num] = getRoot(parents[num]);
    }

    bool unionParent(int a, int b)
    {
        int parent_a = getRoot(a), parent_b = getRoot(b);

        if (parent_a != parent_b)
        {
            if (parent_b > parent_a)
            {
                swap(parent_a, parent_b);
            }

            parents[parent_b] = parent_a;
            components--;

            return true;
        }

        return false;
    }
};

class Solution 
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) 
    {
        UnionFind alice(n), bob(n);

        int used_edges = 0;

        for (const vector<int>& edge : edges)
        {
            if (edge[0] == 3)
            {
                bool bAlice = alice.unionParent(edge[1], edge[2]);
                bool bBob = bob.unionParent(edge[1], edge[2]);

                if (bAlice || bBob)
                {
                    used_edges++;
                }
            }
        }

        for (const vector<int>& edge : edges)
        {
            if (edge[0] == 1)
            {
                if (alice.unionParent(edge[1], edge[2]))
                {
                    used_edges++;
                }
            }
            else if (edge[0] == 2)
            {
                if (bob.unionParent(edge[1], edge[2]))
                {
                    used_edges++;
                }
            }
        }

        if (alice.components > 1 || bob.components > 1)
        {
            return -1;
        }

        return edges.size() - used_edges;
    }
};

int main()
{

	return 0;
}