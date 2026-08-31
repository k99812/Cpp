#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    const int INF = 1e9;

    int n, m, ret;
    vector<int> height;

    int dfs(int cnt)
    {
        if (cnt >= ret) return INF;

        int min_h = n, min_pos = -1;

        for (int i = 0; i < m; i++)
        {
            if (height[i] < min_h)
            {
                min_h = height[i];
                min_pos = i;
            }
        }

        if (min_h == n)
        {
            ret = min(ret, cnt);
            return cnt;
        }

        int end_pos = min_pos;
        while (end_pos < m && height[end_pos] == min_h && (end_pos - min_pos + 1) <= (n - min_h))
        {
            end_pos++;
        }
        int max_width = end_pos - min_pos;

        int ans = INF;
        for (int k = max_width; k >= 1; k--)
        {
            for (int i = 0; i < k; i++) height[min_pos + i] += k;

            ret = min(ret, dfs(cnt + 1));

            for (int i = 0; i < k; i++) height[min_pos + i] -= k;
        }

        return ret;
    }

public:
    Solution() : n(0), m(0), ret(0)
    {

    }

    int tilingRectangle(int N, int M) 
    {
        n = N, m = M;
        ret = INF;
        height.assign(m, 0);

        return dfs(0);
    }
};

int main()
{

	return 0;
}