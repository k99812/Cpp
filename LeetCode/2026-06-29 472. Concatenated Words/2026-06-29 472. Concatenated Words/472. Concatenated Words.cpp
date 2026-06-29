#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct TrieNode
{
    TrieNode* child[26];
    string word;

public:
    TrieNode() : child(), word("")
    {

    }

    void insert(const string& inStr)
    {
        TrieNode* curr = this;

        for (const char c : inStr)
        {
            if (curr->child[c - 'a'] == nullptr)
            {
                curr->child[c - 'a'] = new TrieNode();
            }

            curr = curr->child[c - 'a'];
        }

        curr->word = inStr;
    }
};

class Solution 
{
    vector<int> dp;

    bool dfs(int idx, const string& word, TrieNode* root)
    {
        if (idx == word.size()) return true;

        int& ret = dp[idx];
        if (ret != -1) return ret;

        ret = 0;

        TrieNode* curr = root;

        for (int i = idx; i < word.size(); i++)
        {
            if (curr->child[word[i] - 'a'] == nullptr) break;

            curr = curr->child[word[i] - 'a'];

            if (curr->word != "")
            {
                if (dfs(i + 1, word, root))
                {
                    return ret = true;
                }
            }
        }

        return ret;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
    {
        sort(words.begin(), words.end(), [](const string& a, const string& b)
        {
            return a.size() < b.size();
        });

        TrieNode* root = new TrieNode();
        vector<string> ret;

        for (const string& word : words)
        {
            if (word.empty()) continue;

            dp.assign(word.size(), -1);

            if (dfs(0, word, root))
            {
                ret.push_back(word);
            }

            root->insert(word);
        }

        return ret;
    }
};

int main()
{

	return 0;
}