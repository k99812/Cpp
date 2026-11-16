#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    struct Apple
    {
        int cnt, day;

        bool operator<(const Apple& other) const
        {
            return day > other.day;
        }
    };

public:
    int eatenApples(vector<int>& apples, vector<int>& days) 
    {
        int n = apples.size(), ret = 0;

        priority_queue<Apple> pq;
        for (int day = 0; day < n || pq.size(); day++)
        {
            if (day < n && apples[day])
            {
                pq.push({ apples[day], day + days[day] - 1 });
            }
            
            while (pq.size() && pq.top().day < day)
            {
                pq.pop();
            }

            if (pq.size())
            {
                Apple now = pq.top();
                pq.pop();

                ret++;
                if (--now.cnt != 0)
                {
                    pq.push(now);
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