#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> st;

        for (int i = 0; i < n; i++)
        {
            while (st.size() && st.back() > nums[i] && st.size() + (n - i) > k)
            {
                st.pop_back();
            }

            if (st.size() < k)
            {
                st.push_back(nums[i]);
            }
        }

        return st;
    }
};

int main()
{

	return 0;
}