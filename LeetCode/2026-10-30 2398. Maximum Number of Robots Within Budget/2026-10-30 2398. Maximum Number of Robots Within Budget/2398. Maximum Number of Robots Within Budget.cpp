#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    typedef long long ll;

public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) 
    {
        int n = chargeTimes.size();

        deque<int> dq;
        int left = 0, ret = 0;
        ll sum = 0;

        for (int right = 0; right < n; right++)
        {
            while (dq.size() && dq.back() < chargeTimes[right])
            {
                dq.pop_back();
            }

            dq.push_back(chargeTimes[right]);
            sum += runningCosts[right];

            while (dq.size() && dq.front() + (right - left + 1) * sum > budget)
            {
                if (dq.front() == chargeTimes[left])
                {
                    dq.pop_front();
                }

                sum -= runningCosts[left++];
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