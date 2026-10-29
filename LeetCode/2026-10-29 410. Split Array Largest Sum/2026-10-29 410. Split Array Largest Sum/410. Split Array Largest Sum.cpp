#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    bool go(int mid, vector<int>& nums, int k)
    {
        int cnt = 1, sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > mid) return false;

            sum += nums[i];
            if (sum > mid)
            {
                sum = nums[i];
                cnt++;
            }
        }

        return cnt <= k;
    }

public:
    int splitArray(vector<int>& nums, int k) 
    {
        int left = 0, right = 1e9, ret = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (go(mid, nums, k))
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