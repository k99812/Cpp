#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    const int INF = 1e9;
    vector<vector<int>> dist;

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        dist.assign(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }

        for(const vector<int>& edge:edges)
        { 
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int ret = -1;
        int min_cnt = INF;
        for (int i = 0; i < n; i++)
        {
            int neighbor = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j && dist[i][j] <= distanceThreshold)
                {
                    neighbor++;
                }
            }

            if (neighbor <= min_cnt)
            {
                ret = i;
                min_cnt = neighbor;
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}