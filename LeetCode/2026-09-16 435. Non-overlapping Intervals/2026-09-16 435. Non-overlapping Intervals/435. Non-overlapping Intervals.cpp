#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end());

        int right = intervals[0][1], ret = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            int x1 = intervals[i][0], x2 = intervals[i][1];

            if (right <= x1)
            {
                right = x2;
            }
            else
            {
                ret++;
                right = min(right, x2);
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}