#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution 
{
    struct UnionFind
    {
        unordered_map<char, char> parents;

        UnionFind() {}
        
        char getRoot(char c)
        {
            if (parents[c] == 0 || parents[c] == c) return parents[c] = c;
            return parents[c] = getRoot(parents[c]);
        }

        bool unionParents(char a, char b)
        {
            char root_a = getRoot(a), root_b = getRoot(b);

            if (root_a != root_b)
            {
                if (root_a > root_b)
                {
                    swap(root_a, root_b);
                }

                parents[root_b] = root_a;

                return true;
            }

            return false;
        }
    };

public:
    bool equationsPossible(vector<string>& equations) 
    {
        UnionFind uf;
        vector<pair<char, char>> v;

        for (const string& s : equations)
        {
            char a = s[0], b = s[3];
            if (s[1] == '=')
            {
                uf.unionParents(a, b);
            }
            else
            {
                v.push_back({ a, b });
            }
        }

        for (const auto& [a, b] : v)
        {
            if (uf.getRoot(a) == uf.getRoot(b)) return false;
        }

        return true;
    }
};

int main()
{

	return 0;
}