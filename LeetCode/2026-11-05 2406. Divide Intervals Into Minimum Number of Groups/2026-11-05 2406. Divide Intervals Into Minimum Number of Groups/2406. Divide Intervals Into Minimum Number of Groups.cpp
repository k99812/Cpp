#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
public:
    int minGroups(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++)
        {
            int l = intervals[i][0], r = intervals[i][1];

            if (pq.size() && pq.top() < l)
            {
                pq.pop();
            }

            pq.push(r);
        }

        return pq.size();
    }

    int minGroups(vector<vector<int>>& intervals)
    {
        int n = intervals.size();

        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++)
        {
            v.push_back({ intervals[i][0], +1 });
            v.push_back({ intervals[i][1] + 1, -1 });
        }

        sort(v.begin(), v.end());

        int now = 0, ret = 0;
        for (const auto& [time, type] : v)
        {
            now += type;
            ret = max(ret, now);
        }

        return ret;
    }
};

int main()
{

	return 0;
}