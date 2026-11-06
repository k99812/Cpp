#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

class Solution 
{
    typedef long long ll;

    bool go(ll mid, vector<int>& r, int cars)
    {
        ll total = 0;
        for (int i = 0; i < r.size(); i++)
        {
            total += (ll)sqrt(mid / r[i]);

            if (total >= cars) return true;
        }

        return total >= cars;
    }

public:
    long long repairCars(vector<int>& ranks, int cars) 
    {
        sort(ranks.begin(), ranks.end());

        ll left = 1, right = 1e14, ret = INT64_MAX;
        while (left <= right)
        {
            ll mid = left + (right - left) / 2;

            if (go(mid, ranks, cars))
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