#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    typedef long long ll;

    int n;

    bool go(int mid, vector<int>& bloomDay, int m, int k)
    {
        int bouquet = 0, cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= mid)
            {
                cnt++;

                if (cnt == k)
                {
                    bouquet++;
                    cnt = 0;
                }
            }
            else
            {
                cnt = 0;
            }
        }

        return bouquet >= m;
    }

public:
    Solution() : n(0) {}

    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        n = bloomDay.size();

        if (n < (ll)m * k) return -1;

        int left = 1, right = 1e9, ret = 1e9;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (go(mid, bloomDay, m, k))
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