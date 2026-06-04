#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution 
{
    string begin, end;
    vector<string> path;
    unordered_map<string, int> dist;
    vector<vector<string>> ret;
    unordered_set<string> set;

    void bfs()
    {
        queue<pair<string, int>> q;
        q.push({ begin, 1 });
        dist[begin] = 1;

        while (q.size())
        {
            string now = q.front().first;
            int nowDist = q.front().second;
            q.pop();

            if (now == end) return;

            for (int i = 0; i < now.size(); i++)
            {
                char original = now[i];

                for (char c = 'a'; c <= 'z'; c++)
                {
                    if (c == original) continue;

                    now[i] = c;

                    if (set.count(now) && !dist.count(now))
                    {
                        dist[now] = nowDist + 1;
                        q.push({ now, dist[now] });
                    }

                    now[i] = original;
                }
            }
        }
    }

    void dfs(string now)
    {
        if (now == begin)
        {
            vector<string> validPath = path;
            reverse(validPath.begin(), validPath.end());
            ret.push_back(validPath);

            return;
        }

        int nowDist = dist[now];

        for (int i = 0; i < now.size(); i++)
        {
            char original = now[i];

            for (char c = 'a'; c <= 'z'; c++)
            {
                if (c == original) continue;

                now[i] = c;

                if (dist.count(now) && dist[now] == nowDist - 1)
                {
                    path.push_back(now);
                    dfs(now);
                    path.pop_back();
                }
                
                now[i] = original;
            }
        }
    }

public:
    Solution()
    {

    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        begin = move(beginWord);
        end = move(endWord);

        set = unordered_set<string>(wordList.begin(), wordList.end());

        bfs();

        if (!dist.count(end)) return ret;

        path.push_back(end);
        dfs(end);

        return ret;
    }
};

int main()
{
    string beginWord = "hit", endWord = "cog";
    vector<string> input = { "hot", "dot", "dog", "lot", "log", "cog" };

    Solution sol = Solution();
    vector<vector<string>> ret = sol.findLadders(beginWord, endWord, input);

    for (const vector<string>& i : ret)
    {
        for (const string& s : i)
        {
            cout << s << " ";
        }
        cout << "\n";
    }

	return 0;
}