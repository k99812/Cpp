#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class TreeAncestor 
{
    int LOG;
    vector<vector<int>> parents;

public:
    TreeAncestor(int n, vector<int>& parent) 
    {
        LOG = log2(n) + 1;
        parents.assign(n, vector<int>(LOG + 1, -1));

        for (int i = 0; i < n; i++)
        {
            parents[i][0] = parent[i];
        }

        for (int j = 1; j < LOG; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (parents[i][j - 1] == -1) continue;
                parents[i][j] = parents[parents[i][j - 1]][j - 1];
            }
        }
    }

    int getKthAncestor(int node, int k) 
    {
        for (int j = 0; j < LOG; j++)
        {
            if (k & (1 << j))
            {
                node = parents[node][j];
                if (node == -1) return -1;
            }
        }

        return node;
    }
};

int main()
{

	return 0;
}