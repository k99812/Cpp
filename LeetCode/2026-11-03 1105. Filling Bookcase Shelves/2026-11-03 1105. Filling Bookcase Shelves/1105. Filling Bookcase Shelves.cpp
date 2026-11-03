#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    const int INF = 1e9;

    int n;
    vector<int> dp;

    int dfs(int idx, vector<vector<int>>& books, int w)
    {
        if (idx >= n) return 0;

        int& ret = dp[idx];
        if (ret != -1) return ret;

        ret = INF;

        int now_w = 0, max_h = 0;
        for (int i = idx; i < n; i++)
        {
            now_w += books[i][0];

            if (now_w > w) break;

            max_h = max(max_h, books[i][1]);
            ret = min(ret, max_h + dfs(i + 1, books, w));
        }

        return ret;
    }

public:
    Solution() : n(0) {}

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) 
    {
        n = books.size();
        dp.assign(n, -1);

        return dfs(0, books, shelfWidth);
    }
};

int main()
{

	return 0;
}