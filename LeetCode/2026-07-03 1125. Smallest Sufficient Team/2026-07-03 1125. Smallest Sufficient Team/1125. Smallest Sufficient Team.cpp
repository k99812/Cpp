#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution 
{
    const int INF = 1e9;

    int n, skill_num;
    vector<int> bit_people;
    vector<vector<int>> dp;
    vector<vector<bool>> choice;
    unordered_map<string, int> skills;

    int dfs(int idx, int bit)
    {
        if (bit == (1 << skill_num) - 1) return 0;
        if (idx == n) return INF;

        int& ret = dp[idx][bit];
        if (ret != -1) return ret;

        ret = 0;

        int skip = dfs(idx + 1, bit);
        int take = INF, next_bit = bit | bit_people[idx];

        if (next_bit != bit)
        {
            take = dfs(idx + 1, next_bit) + 1;
        }

        if (take < skip)
        {
            choice[idx][bit] = true;
            ret = take;
        }
        else
        {
            choice[idx][bit] = false;
            ret = skip;
        }
        
        return ret;
    }

public:
    Solution() : n(0), skill_num(0) 
    {

    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) 
    {
        n = people.size();
        skill_num = req_skills.size();
        bit_people.assign(n, 0);
        choice.assign(n, vector<bool>(1 << skill_num, false));
        dp.assign(n, vector<int>(1 << skill_num, -1));

        for (int i = 0; i < skill_num; i++)
        {
            skills[req_skills[i]] = i;
        }

        for (int i = 0; i < n; i++)
        {
            int bit = 0;

            for (const string& s : people[i])
            {
                if (skills.count(s))
                {
                    bit |= (1 << skills[s]);
                }
            }

            bit_people[i] = bit;
        }

        dfs(0, 0);

        int bit = 0;
        vector<int> ret;

        for (int i = 0; i < n; i++)
        {
            if (choice[i][bit])
            {
                bit |= bit_people[i];
                ret.push_back(i);
            }
        }
            
        return ret;
    }
};

int main()
{

    return 0;
}