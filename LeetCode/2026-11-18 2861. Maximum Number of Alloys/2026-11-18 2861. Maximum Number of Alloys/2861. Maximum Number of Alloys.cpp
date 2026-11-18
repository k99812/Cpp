#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    typedef long long ll;

    int n, k, budget;

    int go(ll mid, vector<vector<int>>& com, vector<int>& stock, vector<int>& cost)
    {
        for (int i = 0; i < k; i++)
        {
            ll total = 0;

            for (int j = 0; j < n; j++)
            {
                ll need = mid * com[i][j];

                if (need > stock[j])
                {
                    total += cost[j] * (need - stock[j]);
                }

                if (total > budget) break;
            }

            if (total <= budget) return true;
        }

        return false;
    }

public:
    Solution() : n(0), k(0), budget(0) {}

    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, 
        vector<int>& stock, vector<int>& cost) 
    {
        this->n = n, this->k = k, this->budget = budget;

        ll left = 0, right = 2e8, ret = 0;
        while (left <= right)
        {
            ll mid = left + (right - left) / 2;

            if (go(mid, composition, stock, cost))
            {
                ret = mid;
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