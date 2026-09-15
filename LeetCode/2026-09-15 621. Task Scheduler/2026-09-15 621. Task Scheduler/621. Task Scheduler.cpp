#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

struct Node
{
    char c;
    int n;
    
    bool operator<(const Node& other) const
    {
        if (n == other.n) return c > other.c;
        return n < other.n;
    }
};

class Solution 
{
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        priority_queue<Node> pq;
        unordered_map<char, int> task_map;

        for (char task : tasks)
        {
            task_map[task]++;
        }

        for (const auto& [task, num] : task_map)
        {
            pq.push({ task, num });
        }

        int ret = 0;

        while (pq.size())
        {
            vector<Node> temp;
            int cycle = n + 1, cnt = 0;

            while (cycle-- && pq.size())
            {
                Node now = pq.top();
                pq.pop();

                now.n--;
                temp.push_back(now);
                cnt++;
            }

            for (Node& node : temp)
            {
                if (node.n) pq.push(node);
            }

            if (pq.empty())
            {
                ret += cnt;
            }
            else
            {
                ret += (n + 1);
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}