#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    int l, h;

    void dfs(int now, int num, vector<int>& ret)
    {
        if (now > h) return;

        if (l <= now)
        {
            ret.push_back(now);
        }

        if (num > 9) return;

        dfs(now * 10 + num, num + 1, ret);
    }

public:
    Solution() : l(0), h(0)
    {

    }

    vector<int> sequentialDigits(int low, int high) 
    {
        l = low, h = high;
        vector<int> ret;

        for (int i = 1; i <= 9; i++)
        {
            dfs(0, i, ret);
        }

        sort(ret.begin(), ret.end());

        return ret;
    }
};

int main()
{
    Solution sol = Solution();
    vector<int> ret = sol.sequentialDigits(1000, 13000);
    
    for (const int i : ret)
    {
        cout << i << " ";
    }

	return 0;
}