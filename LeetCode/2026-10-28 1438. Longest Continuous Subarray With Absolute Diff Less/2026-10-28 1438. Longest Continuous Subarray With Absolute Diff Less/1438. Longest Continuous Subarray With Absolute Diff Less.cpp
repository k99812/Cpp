#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
public:
    int longestSubarray(vector<int>& nums, int limit) 
    {
        int n = nums.size();
        deque<int> min_dq, max_dq;

        int left = 0, ret = 0;
        
        for (int right = 0; right < n; right++)
        {
            while (min_dq.size() && min_dq.back() > nums[right])
            {
                min_dq.pop_back();
            }

            while (max_dq.size() && max_dq.back() < nums[right])
            {
                max_dq.pop_back();
            }

            min_dq.push_back(nums[right]);
            max_dq.push_back(nums[right]);
            
            while (max_dq.front() - min_dq.front() > limit)
            {
                if (min_dq.front() == nums[left]) min_dq.pop_front();
                if (max_dq.front() == nums[left]) max_dq.pop_front();

                left++;
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