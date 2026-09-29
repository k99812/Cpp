#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> lis;
        for (const int num : nums)
        {
            auto itr = lower_bound(lis.begin(), lis.end(), num);

            if (itr == lis.end())
            {
                lis.push_back(num);
            }
            else
            {
                *itr = num;
            }
        }

        return lis.size();
    }
};

int main()
{

	return 0;
}