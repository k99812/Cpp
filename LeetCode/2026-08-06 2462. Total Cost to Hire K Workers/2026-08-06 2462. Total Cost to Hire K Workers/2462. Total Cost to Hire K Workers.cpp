#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

typedef long long ll;

struct point
{
    int cost, idx;

    bool operator<(const point& other) const
    {
        if (cost == other.cost) return idx > other.idx;
        return cost > other.cost;
    }
};

class Solution 
{
public:
    ll totalCost(vector<int>& costs, int k, int candidates) 
    {
        priority_queue<point> left_pq, right_pq;

        int left = 0, right = costs.size() - 1;
        for (; left < candidates && left <= right; left++)
        {
            left_pq.push({ costs[left], left });
        }

        for (int i = 0; i < candidates && left <= right; i++)
        {
            right_pq.push({ costs[right], right-- });
        }

        ll ret = 0;
        for (int step = 0; step < k; step++)
        {
            if (right_pq.empty() || (left_pq.size() && right_pq.top() < left_pq.top()))
            {
                ret += left_pq.top().cost;
                left_pq.pop();

                if (left <= right)
                {
                    left_pq.push({ costs[left], left++ });
                }
            }
            else
            {
                ret += right_pq.top().cost;
                right_pq.pop();

                if (left <= right)
                {
                    right_pq.push({ costs[right], right-- });
                }
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}