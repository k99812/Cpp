#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    typedef long long ll;

    int n;
    vector<int> visited;

    int dfs(int now, vector<vector<int>>& bombs)
    {
        int cnt = 1;
        visited[now] = true;

        ll x1 = bombs[now][0], y1 = bombs[now][1], r1 = bombs[now][2];

        for (int next = 0; next < n; next++)
        {
            if (visited[next]) continue;

            ll dx = x1 - bombs[next][0];
            ll dy = y1 - bombs[next][1];

            if (dx * dx + dy * dy <= r1 * r1)
            {
                cnt += dfs(next, bombs);
            }
        }

        return cnt;
    }

public:
    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        n = bombs.size();
        int ret = 0;

        for (int i = 0; i < n; i++)
        {
            visited.assign(n, 0);
            ret = max(ret, dfs(i, bombs));
        }

        return ret;
    }
};

int main()
{

	return 0;
}