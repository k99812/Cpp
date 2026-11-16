#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    bool go(int mid, int n, vector<int>& q)
    {
        int cnt = 0;
        for (int i = 0; i < q.size(); i++)
        {
            cnt += q[i] / mid;
            cnt += q[i] % mid ? 1 : 0;
        }

        return cnt <= n;
    }

public:
    int minimizedMaximum(int n, vector<int>& quantities) 
    {
        int left = 1, right = 1e5, ret = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (go(mid, n, quantities))
            {
                ret = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}