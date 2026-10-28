#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    typedef long long ll;

    bool go(int mid, int t, vector<int>& nums)
    {
        ll cnt = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            cnt += (nums[i] - 1) / mid;
        }

        return cnt <= t;
    }

public:
    int minimumSize(vector<int>& nums, int maxOperations) 
    {
        int left = 1, right = 1e9, ret = 1e9;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (go(mid, maxOperations, nums))
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