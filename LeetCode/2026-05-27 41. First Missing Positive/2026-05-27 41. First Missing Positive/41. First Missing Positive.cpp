#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    int n;
    vector<int> nums;

public:
    int firstMissingPositive(vector<int>& input) 
    {
        nums = move(input);
        n = nums.size();
    }
};

int main()
{
    vector<int> nums = { 1, 2, 0 };

    Solution sol = Solution();
    cout << sol.firstMissingPositive(nums) << "\n";

	return 0;
}