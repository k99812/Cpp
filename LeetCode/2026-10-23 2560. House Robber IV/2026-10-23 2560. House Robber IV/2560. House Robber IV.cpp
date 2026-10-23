#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    bool check(int mid, int k, vector<int>& nums)
    {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= mid)
            {
                i++;
                cnt++;
            }
            
        }

        return cnt >= k;
    }

public:
    int minCapability(vector<int>& nums, int k) 
    {
        int left = 1, right = 1e9, ret = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (check(mid, k, nums))
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