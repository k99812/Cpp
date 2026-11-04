#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    struct Node
    {
        int idx, arr, lev, chair;

        bool operator<(const Node& other) const
        {
            if (lev == other.lev) return chair > other.chair;
            return lev > other.lev;
        }
    };

public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) 
    {
        int n = times.size();

        vector<Node> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = { i, times[i][0], times[i][1], -1 };
        }

        sort(v.begin(), v.end(),
            [](const Node& a, const Node& b)
        {
            if (a.arr == b.arr) return a.lev < b.lev;
            return a.arr < b.arr;
        });

        priority_queue<Node> used_pq;
        priority_queue<int, vector<int>, greater<int>> empty_pq;

        int chair_id = 0;
        for (Node& node : v)
        {
            while (used_pq.size() && used_pq.top().lev <= node.arr)
            {
                empty_pq.push(used_pq.top().chair);
                used_pq.pop();
            }

            int next_id = -1;
            if (empty_pq.size())
            {
                next_id = empty_pq.top();
                empty_pq.pop();
            }
            else
            {
                next_id = chair_id++;
            }

            if (node.idx == targetFriend) return next_id;

            node.chair = next_id;
            used_pq.push(node);
        }

        return -1;
    }
};

int main()
{

	return 0;
}