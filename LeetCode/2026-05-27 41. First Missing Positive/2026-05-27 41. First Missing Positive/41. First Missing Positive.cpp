#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    int n;
    vector<int> nums;

public:
    Solution() : n(0)
    {

    }

    int firstMissingPositive(vector<int>& input) 
    {
        nums = move(input);
        n = nums.size();

        for (int i = 0; i < n; i++)
        {
            while (0 < nums[i] && nums[i] <= n && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }

        return n + 1;
    }
};

int main()
{
    vector<int> nums = { 1, 2, 0 };

    Solution sol = Solution();
    cout << sol.firstMissingPositive(nums) << "\n";

	return 0;
}