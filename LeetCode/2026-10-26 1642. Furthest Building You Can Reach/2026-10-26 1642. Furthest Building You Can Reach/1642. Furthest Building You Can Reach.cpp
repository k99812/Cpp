#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    struct Node
    {
        int cost;

        bool operator<(const Node other) const
        {
            return cost > other.cost;
        }
    };

public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
        int n = heights.size();
        priority_queue<Node> pq;

        int now = 1e9;
        for (int i = 0; i < n; i++)
        {
            if (heights[i] > now)
            {
                int cost = heights[i] - now;
                pq.push({ cost });

                if (pq.size() > ladders)
                {
                    int min_cost = pq.top().cost;
                    pq.pop();

                    if (min_cost > bricks)
                    {
                        return i - 1;
                    }

                    bricks -= min_cost;
                }
            }

            now = heights[i];
        }

        return n - 1;
    } 
};

int main()
{

	return 0;
}