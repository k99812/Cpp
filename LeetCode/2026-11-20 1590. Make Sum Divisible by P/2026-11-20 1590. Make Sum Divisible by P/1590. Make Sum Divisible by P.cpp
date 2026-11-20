#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution 
{
public:
    int minSubarray(vector<int>& nums, int p) 
    {
        int n = nums.size();
        int r = 0;

        for (int n : nums)
        {
            r = (r + n) % p;
        }

        if (r == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;

        int cur = 0, ret = n;

        for (int i = 0; i < n; i++)
        {
            cur = (cur + nums[i]) % p;

            int target = (cur - r + p) % p;

            if (mp.count(target))
            {
                ret = min(ret, i - mp[target]);
            }

            mp[cur] = i;
        }

        return ret == n ? -1 : ret;
    }
};

int main()
{

	return 0;
}