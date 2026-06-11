#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution 
{
    int n;
    string s;
    vector<string> ret;
    unordered_set<string> dict;

    void dfs(int idx, string str)
    {
        if (idx > n) return;

        if (idx == n)
        {
            str.pop_back();
            ret.push_back(str);

            return;
        }

        string now = "";
        for (int i = idx; i < n; i++)
        {
            now += s[i];
            if (dict.count(now))
            {
                dfs(i + 1, str + now + " ");
            }
        }
    }

public:
    Solution() : n(0)
    {

    }

    vector<string> wordBreak(string str, vector<string>& wordDict) 
    {
        s = move(str);
        n = s.size();

        dict = unordered_set<string>(wordDict.begin(), wordDict.end());

        dfs(0, "");

        return ret;
    }
};

int main()
{
    string str = "catsanddog";
    vector<string> wordDict = { "cat", "cats", "and", "sand", "dog" };

    Solution sol = Solution();
    vector<string> ret = sol.wordBreak(str, wordDict);

    for (const string& s : ret)
    {
        cout << s << "\n";
    }

	return 0;
}