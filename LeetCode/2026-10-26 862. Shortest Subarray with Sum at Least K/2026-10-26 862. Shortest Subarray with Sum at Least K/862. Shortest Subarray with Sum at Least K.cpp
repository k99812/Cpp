#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    typedef long long ll;

public:
    int shortestSubarray(vector<int>& nums, int k) 
    {
        int n = nums.size();

        vector<ll> psum(n, 0);
        psum[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            psum[i] = psum[i - 1] + nums[i];
        }

        deque<int> dq;
        int ret = 1e9;

        for (int i = 0; i < n; i++)
        {
            if (psum[i] >= k)
            {
                ret = min(ret, i + 1);
            }

            while (dq.size() && psum[i] - psum[dq.front()] >= k)
            {
                ret = min(ret, i - dq.front());
                dq.pop_front();
            }

            while (dq.size() && psum[dq.back()] >= psum[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return ret == 1e9 ? -1 : ret;
    }
};

int main()
{

	return 0;
}