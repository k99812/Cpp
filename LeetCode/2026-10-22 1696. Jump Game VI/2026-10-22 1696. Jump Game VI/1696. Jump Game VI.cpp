#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
public:
    int maxResult(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        deque<int> dq;

        dp[0] = nums[0];
        dq.push_back(0);

        for (int i = 1; i < n; i++)
        {
            if (dq.size() && dq.front() < i - k)
            {
                dq.pop_front();
            }

            dp[i] = nums[i] + dp[dq.front()];

            while (dq.size() && dp[dq.back()] <= dp[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return dp[n - 1];
    }
};

int main()
{

	return 0;
}