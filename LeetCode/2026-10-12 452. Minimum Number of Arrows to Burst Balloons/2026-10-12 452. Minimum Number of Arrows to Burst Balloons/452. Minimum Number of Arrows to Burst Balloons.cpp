#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b)
        {
            return a[1] < b[1];
        });

        int ret = 1;
        int pos = points[0][1];

        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > pos)
            {
                ret++;
                pos = points[i][1];
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}