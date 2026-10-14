#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    bool go(int val, int n, int m, vector<int>& position)
    {
        int cnt = 1, prev = position[0];

        for (int i = 1; i < n; i++)
        {
            if (position[i] - prev >= val)
            {
                cnt++;
                prev = position[i];

                if (cnt >= m) return true;
            }
        }

        return false;
    }

public:
    int maxDistance(vector<int>& position, int m) 
    {
        sort(position.begin(), position.end());

        int n = position.size();

        int left = 1, right = position.back() - position.front(), ret = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (go(mid, n, m, position))
            {
                ret = max(ret, mid);
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}