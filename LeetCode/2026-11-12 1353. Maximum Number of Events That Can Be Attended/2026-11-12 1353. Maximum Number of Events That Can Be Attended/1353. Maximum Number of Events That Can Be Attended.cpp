#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
public:
    int maxEvents(vector<vector<int>>& events) 
    {
        int n = events.size();

        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> pq;

        int day = 0, i = 0, ret = 0;
        while (i < n || pq.size())
        {
            if (pq.empty())
            {
                day = events[i][0];
            }

            while (i < n && events[i][0] <= day)
            {
                pq.push(events[i][1]);
                i++;
            }

            while (pq.size() && pq.top() < day)
            {
                pq.pop();
            }

            if (pq.size())
            {
                pq.pop();
                ret++;
                day++;
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}