#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    int longestNiceSubarray(vector<int>& nums) 
    {
        int left = 0, bit = 0, ret = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            while (bit & nums[right])
            {
                bit ^= nums[left++];
            }

            bit |= nums[right];
            ret = max(ret, right - left + 1);
        }

        return ret;
    }
};

int main()
{


    return 0;
}