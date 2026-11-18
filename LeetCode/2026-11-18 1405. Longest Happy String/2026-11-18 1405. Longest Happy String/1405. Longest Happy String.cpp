#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

class Solution 
{ 
    struct Node
    {
        char c;
        int cnt;

        bool operator<(const Node& other) const
        {
            return cnt < other.cnt;
        }
    };

public:
    string longestDiverseString(int a, int b, int c) 
    {
        int n = a + b + c;
        string ret = "";
        
        priority_queue<Node> pq;
        if (a > 0) pq.push({ 'a', a });
        if (b > 0) pq.push({ 'b', b });
        if (c > 0) pq.push({ 'c', c });

        while (pq.size())
        {
            Node now = pq.top();
            pq.pop();

            if (ret.size() >= 2 && ret[ret.size() - 1] == now.c && ret[ret.size() - 2] == now.c)
            {
                if (pq.empty()) break;

                Node temp = now;
                now = pq.top();
                pq.pop();
                pq.push(temp);
            }

            ret.push_back(now.c);
            if (--now.cnt > 0)
            {
                pq.push(now);
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}