#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    typedef long long ll;

    bool go(ll mid, vector<int>& time, int total)
    {
        ll cnt = 0;
        for (int i = 0; i < time.size(); i++)
        {
            cnt += mid / time[i];
        }

        return cnt >= total;
    }

public:
    long long minimumTime(vector<int>& time, int totalTrips) 
    {
        ll min_time = *min_element(time.begin(), time.end());

        ll left = 1, right = min_time * totalTrips, ret = INT64_MAX;

        while (left <= right)
        {
            ll mid = left + (right - left) / 2;

            if (go(mid, time, totalTrips))
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