#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    struct Node
    {
        int score, age;

        bool operator<(const Node& other) const
        {
            if (age == other.age) return score < other.score;
            return age < other.age;
        }
    };

    int n;
    vector<vector<int>> dp;
    vector<Node> v;

    int dfs(int idx, int prev)
    {
        if (idx >= n) return 0;

        int& ret = dp[idx][prev + 1];
        if (ret != -1) return ret;

        ret = 0;

        int skip = dfs(idx + 1, prev);
        int take = 0;
        if (prev == -1 || v[prev].score <= v[idx].score)
        {
            take = v[idx].score + dfs(idx + 1, idx);
        }
        
        return ret = max(skip, take);
    }

public:
    Solution() : n(0) {}

    int bestTeamScore(vector<int>& scores, vector<int>& ages) 
    {
        n = scores.size();
        dp.assign(n, vector<int>(n + 1, -1));
        v.assign(n, {});

        for (int i = 0; i < n; i++)
        {
            v[i] = { scores[i], ages[i] };
        }

        sort(v.begin(), v.end());

        return dfs(0, -1);
    }
};

int main()
{

    return 0;
}