#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    typedef long long ll;

public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());

        int left = 0, ret = 0;
        ll sum = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            ll op_cnt = (ll)nums[right] * (right - left + 1) - sum;

            while (op_cnt > k)
            {
                op_cnt -= (nums[right] - nums[left]);
                sum -= nums[left++];
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