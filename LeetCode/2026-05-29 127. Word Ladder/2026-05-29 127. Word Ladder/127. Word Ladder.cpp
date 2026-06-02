#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution 
{
    int n;
    string begin, end;
    unordered_set<string> set;

    int bfs()
    {
        if (set.find(end) == set.end()) return 0;

        queue<pair<string, int>> q;

        q.push({ begin, 1 });

        while (q.size())
        {
            string now = q.front().first;
            int cnt = q.front().second;
            q.pop();

            if (now == end) return cnt;

            for (int i = 0; i < now.size(); i++)
            {
                char original = now[i];

                for (char c = 'a'; c <= 'z'; c++)
                {
                    if (c == original) continue;

                    now[i] = c;

                    if (set.count(now))
                    {
                        q.push({ now, cnt + 1 });
                        set.erase(now);
                    }
                }

                now[i] = original;
            }
        }

        return 0;
    }

public:
    Solution() : n(0), begin(""), end("")
    {

    }

    int ladderLength(string beginWord, string endWord, vector<string>& input) 
    {
        begin = move(beginWord);
        end = move(endWord);
        
        set = unordered_set<string>(input.begin(), input.end());
        
        return bfs();
    }
};

int main()
{
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = { "hot", "dot", "dog", "lot", "log", "cog" };

    Solution sol = Solution();
    cout << sol.ladderLength(beginWord, endWord, wordList) << "\n";

	return 0;
}