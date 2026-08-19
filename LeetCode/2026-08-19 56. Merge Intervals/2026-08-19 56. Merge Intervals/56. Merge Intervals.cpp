#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> ret;
       
        sort(intervals.begin(), intervals.end());

        int left = intervals[0][0], right = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= right)
            {
                right = max(right, intervals[i][1]);
            }
            else
            {
                ret.push_back({ left, right });

                left = intervals[i][0], right = intervals[i][1];
            }
        }

        ret.push_back({ left, right });

        return ret;
    }
};

int main()
{

	return 0;
}