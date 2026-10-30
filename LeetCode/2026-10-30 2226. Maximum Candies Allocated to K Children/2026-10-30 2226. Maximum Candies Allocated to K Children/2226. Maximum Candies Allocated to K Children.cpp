#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    typedef long long ll;

    bool go(int mid, ll k, vector<int>& candies)
    {
        ll cnt = 0;
        for (int i = 0; i < candies.size(); i++)
        {
            cnt += candies[i] / mid;

            if (cnt >= k) return true;
        } 

        return false;
    }

public:
    int maximumCandies(vector<int>& candies, long long k) 
    {
        int left = 1, right = 1e7, ret = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (go(mid, k, candies))
            {
                ret = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}