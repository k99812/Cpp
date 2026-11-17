#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    bool go(int mid, const vector<int>& nums)
    {
        long long extra = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            extra += mid - nums[i];

            if (extra < 0) return false;
        }

        return true;
    }

public:
    int minimizeArrayValue(vector<int>& nums) 
    {
        int left = 0, right = *max_element(nums.begin(), nums.end()), ret = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (go(mid, nums))
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