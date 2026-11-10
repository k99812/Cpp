#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    bool go(int mid, vector<int>& nums, int p)
    {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i + 1] - nums[i] <= mid)
            {
                cnt++;
                i++;
                if (cnt >= p) return true;
            }
        }

        return cnt >= p;
    }

public:
    int minimizeMax(vector<int>& nums, int p) 
    {
        sort(nums.begin(), nums.end());

        int left = 0, right = nums.back(), ret = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (go(mid, nums, p))
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