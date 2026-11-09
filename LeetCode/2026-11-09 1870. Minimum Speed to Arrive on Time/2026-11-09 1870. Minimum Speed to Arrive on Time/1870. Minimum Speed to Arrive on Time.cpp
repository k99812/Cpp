#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

class Solution 
{
    bool go(int speed, double hour, vector<int>& dist)
    {
        double time = 0;
        for (int i = 0; i < dist.size() - 1; i++)
        {
            time += ceil((double)dist[i] / speed);
        }

        time += (double)dist[dist.size() - 1] / speed;

        return time <= hour;
    }

public:
    int minSpeedOnTime(vector<int>& dist, double hour) 
    {
        int ret = -1;
        int left = 1, right = 1e7;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (go(mid, hour, dist))
            {
                ret = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}