#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int n = nums.size();
        deque<pair<int, int>> dq;
        vector<int> ret;
        
        for (int i = 0; i < n; i++)
        {
            while (dq.size() && dq.back().first <= nums[i])
            {
                dq.pop_back();
            }

            dq.push_back({ nums[i], i });

            while (dq.size() && dq.front().second < i - k + 1)
            {
                dq.pop_front();
            }

            if (i >= k - 1)
            {
                ret.push_back(dq.front().first);
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}