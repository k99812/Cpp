#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int left = 0, ret = 0, cnt = 0;

        for (int right = 0; right < n; right++)
        {
            if (nums[right] == 0) cnt++;

            while (cnt > k)
            {
                if (nums[left++] == 0) cnt--;
            }

            ret = max(ret, right - left + 1);
        }

        return ret;
    }
};

int main()
{
	return 0;
}