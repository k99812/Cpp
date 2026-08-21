#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

struct UnionFind
{
private:
    vector<int> parents;

public:
    UnionFind(int n)
    {
        parents.assign(n, 0);

        for (int i = 0; i < n; i++)
        {
            parents[i] = i;
        }
    }

    int getRoot(int num)
    {
        if (num == parents[num]) return num;
        return parents[num] = getRoot(parents[num]);
    }

    bool unionParent(int a, int b)
    {
        int rootA = getRoot(a), rootB = getRoot(b);

        if (rootA != rootB)
        {
            parents[rootB] = rootA;
            return true;
        }

        return false;
    }
};

class Solution 
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        int n = accounts.size();
        UnionFind djs = UnionFind(n);

        unordered_map<string, int> account_map;

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string email = accounts[i][j];

                if (account_map.find(email) != account_map.end())
                {
                    djs.unionParent(account_map[email], i);
                }
                else
                {
                    account_map[email] = i;
                }
            }
        }

        unordered_map<int, vector<string>> root_map;
        for (const pair<string, int>& account : account_map)
        {
            string email = account.first;
            int id = account.second;

            root_map[djs.getRoot(id)].push_back(email);
        }

        vector<vector<string>> ret;
        for (auto& [id, email] : root_map)
        {
            sort(email.begin(), email.end());

            vector<string> v;
            v.push_back(accounts[id][0]);
            v.insert(v.end(), email.begin(), email.end());

            ret.push_back(v);
        }

        return ret;
    }
};

int main()
{

	return 0;
}