#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    struct Node
    {
        int pass, total;

        double diff() const
        {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        }

        bool operator<(const Node& other) const
        {
            return diff() < other.diff();
        }
    };

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) 
    {
        int n = classes.size();

        priority_queue<Node> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push({ classes[i][0], classes[i][1] });
        }

        while (extraStudents--)
        {
            Node now = pq.top();
            pq.pop();

            now.pass += 1;
            now.total += 1;

            pq.push(now);
        }

        double ret = 0.0;
        while (pq.size())
        {
            auto [p, t] = pq.top();
            pq.pop();

            ret += (double)p / t;
        }

        return ret / n;
    }
};

int main()
{
	return 0;
}