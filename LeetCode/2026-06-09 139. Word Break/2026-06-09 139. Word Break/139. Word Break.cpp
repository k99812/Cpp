#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include <unordered_set>

using namespace std;

class Solution 
{
    int n;
    string s;
    vector<int> dp;
    vector<string> dict2;
    unordered_set<string> dict;

    bool dfs(int idx)
    {
        if (idx == n) return true;

        int& ret = dp[idx];
        if (ret != -1) return ret;

        ret = 0;

        string now = "";
        for (int i = idx; i < n; i++)
        {
            now += s[i];

            if (dict.count(now))
            {
                if (dfs(idx + 1))
                {
                    return ret = 1;
                }
            }
        }

        return ret;
    }

    bool dfs2(int idx)
    {
        if (idx == n) return true;

        int& ret = dp[idx];
        if (ret != -1) return ret;

        ret = 0;

        for (const string& word : dict2)
        {
            int word_len = word.size();

            if (idx + word_len <= s.size() && s.compare(idx, word_len, word) == 0)
            {
                if (dfs(idx + word_len))
                {
                    return ret = 1;
                }
            }
        }

        return ret;
    }

public:
    Solution() : n(0)
    {

    }
    bool wordBreak(string S, vector<string>& wordDict) 
    {
        s = move(S);
        n = s.size();

        dp.assign(n, -1);
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        dict2 = wordDict;

        return dfs(0);
    }
};

int main()
{
    string s = "applepenapple";
    vector<string> wordDict = { "apple", "pen" };

    Solution sol = Solution();
    cout << (sol.wordBreak(s, wordDict) ? "true" : "false") << "\n";

    return 0;
}