#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    typedef long long ll;

    struct task
    {
        int idx, eq, cost;

        bool operator<(const task& other) const
        {
            if (cost == other.cost) return idx > other.idx;
            return cost > other.cost;
        }
    };

public:
    vector<int> getOrder(vector<vector<int>>& tasks) 
    {
        int n = tasks.size();
        vector<int> ret;

        for (int i = 0; i < n; i++)
        {
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end());

        priority_queue<task> pq;
        ll time = tasks[0][0];
        
        for (int i = 0; i < n; i++)
        {
            int eq = tasks[i][0], cost = tasks[i][1], orig_idx = tasks[i][2];

            while (pq.size() && eq > time)
            {
                auto [idx, n_eq, c] = pq.top();
                pq.pop();

                time += c;
                ret.push_back(idx);
            }

            if (eq > time)
            {
                time = eq;
            }

            pq.push({ orig_idx, eq, cost });
        }

        while (pq.size())
        {
            auto [idx, n_eq, c] = pq.top();
            pq.pop();

            ret.push_back(idx);
        }

        return ret;
    }
};

int main()
{

	return 0;
}