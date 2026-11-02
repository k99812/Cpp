#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    struct Node
    {
        int p, c;

        bool operator<(const Node& other) const
        {
            return p < other.p;
        }
    };

public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        int n = profits.size();
        vector<Node> v(n);

        for (int i = 0; i < n; i++)
        {
            v[i] = {profits[i], capital[i]};
        }

        sort(v.begin(), v.end(),
            [](const Node& a, const Node& b)
        {
            return a.c < b.c;
        });

        int cnt = 0;
        priority_queue<Node> pq;
        for (int i = 0; i < n; i++)
        {
            while (pq.size() && w < v[i].c && cnt < k)
            {
                cnt++;
                w += pq.top().p;
                pq.pop();
            }

            if (w < v[i].c || cnt == k) break;

            pq.push({ v[i].p, v[i].c });
        }

        while (pq.size() && cnt < k)
        {
            cnt++;
            w += pq.top().p;
            pq.pop();
        }

        return w;
    }
};

int main()
{

	return 0;
}