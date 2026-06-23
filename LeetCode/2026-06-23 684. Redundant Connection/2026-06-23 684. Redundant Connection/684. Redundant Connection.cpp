#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    int n;
    vector<int> parents;

    int getParents(int num)
    {
        if (parents[num] == num) return num;
        return parents[num] = getParents(parents[num]);
    }

    void unionParents(int a, int b)
    {
        int parent_a = getParents(a), parent_b = getParents(b);

        if (parent_a != parent_b)
        {
            if (parent_a > parent_b)
            {
                swap(parent_a, parent_b);
            }

            parents[parent_b] = parent_a;
        }
    }

public:
    Solution() : n(0)
    {

    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        n = edges.size();
        parents.assign(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            parents[i] = i;
        }


        for (const vector<int>& edge : edges)
        {
            if (getParents(edge[0]) != getParents(edge[1]))
            {
                unionParents(edge[0], edge[1]);
            }
            else
            {
                return { edge[0], edge[1] };
            }
        }

        return { };
    }
};

int main()
{

	return 0;
}