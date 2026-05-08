#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    string str, pattern;
    vector<vector<int>> dp;

private:
    bool dfs(int i, int j)
    {
        if (j == pattern.size())
        {
            return i == str.size();
        }

        int& ret = dp[i][j];
        if (ret != -1) return ret;

        ret = 0;

        bool first_match = (i < str.size() && (str[i] == pattern[j] || pattern[j] == '.'));

        if (j + 1 < pattern.size() && pattern[j + 1] == '*')
        {
            ret = dfs(i, j + 2) || (first_match && dfs(i + 1, j));
        }
        else
        {
            ret = first_match && dfs(i + 1, j + 1);
        }

        return ret;
    }

public:
    bool isMatch(string s, string p) 
    {
        str = s, pattern = p;
        dp.assign(s.size() + 1, vector<int>(p.size() + 1, -1));

        return dfs(0, 0);
    }
};

int main()
{
    string s, p;
    cin >> s >> p;

    Solution sol = Solution();

    cout << (sol.isMatch(s, p) ? "true" : "false") << "\n";

	return 0;
}