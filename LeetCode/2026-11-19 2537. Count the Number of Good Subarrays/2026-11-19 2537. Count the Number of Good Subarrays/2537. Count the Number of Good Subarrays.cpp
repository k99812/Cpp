#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution 
{
    typedef long long ll;

public:
    long long countGood(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int left = 0;
        ll pair_cnt = 0, ret = 0;

        unordered_map<int, int> un_pair;

        for (int right = 0; right < n; right++)
        {
            pair_cnt += un_pair[nums[right]]++;

            while (pair_cnt >= k)
            {
                ret += n - right;

                pair_cnt -= --un_pair[nums[left]];;
                left++;
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}