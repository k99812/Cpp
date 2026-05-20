#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution 
{
private:
    const int dir[2] = { 1 , -1 };

    int n;
    vector<int> arr;
    unordered_map<int, vector<int>> hash;

    int bfs()
    {
        queue<int> q;
        vector<int> dist(n, -1);

        dist[0] = 0;
        q.push(0);

        while (q.size())
        {
            int now = q.front();
            q.pop();

            if (now == n - 1) return dist[now];

            for (int i = 0; i < 2; i++)
            {
                int next = now + dir[i];

                if (next < 0 || next >= n) continue;
                if (dist[next] != -1) continue;

                q.push(next);
                dist[next] = dist[now] + 1;
            }

            if (hash.count(arr[now]))
            {
                for (const int next : hash[arr[now]])
                {
                    if (now == next || dist[next] != -1) continue;

                    q.push(next);
                    dist[next] = dist[now] + 1;
                }

                hash.erase(arr[now]);
            }
        }

        return dist[n - 1];
    }

public:
    Solution() : n(0)
    {

    }

    int minJumps(vector<int>& input) 
    {
        arr = move(input);
        n = arr.size();

        for (int i = 0; i < n; i++)
        {
            hash[arr[i]].push_back(i);
        }

        return bfs();
    }
};

int main()
{
    vector<int> arr = { 100,-23,-23,404,100,23,23,23,3,404 };

    Solution sol = Solution();
    cout << sol.minJumps(arr) << "\n";

    return 0;
}