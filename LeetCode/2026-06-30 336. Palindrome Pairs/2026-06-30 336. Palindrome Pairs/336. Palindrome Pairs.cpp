#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

struct TrieNode
{
    int id;
    TrieNode* chiled[26];
    vector<int> palindrome_ids;

public:
    TrieNode() : chiled(), id(-1)
    {

    }

    void insert(const string& str, const int ID, class Solution* sol);
};

class Solution 
{
    int n;
    vector<vector<int>> ret;

public:
    Solution() : n(0)
    {

    }

    bool isPalindrome(const string& word, int s, int e)
    {
        while (s < e)
        {
            if (word[s++] != word[e--]) return false;
        }
        return true;
    }

    void search(const string& word, const int id, TrieNode* root)
    {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (curr->id != -1 && curr->id != id)
            {
                if (isPalindrome(word, i, word.size() - 1))
                {
                    ret.push_back({ id, curr->id });
                }
            }

            if (curr->chiled[word[i] - 'a'] == nullptr) return;
            curr = curr->chiled[word[i] - 'a'];
        }

        for (int target : curr->palindrome_ids)
        {
            if (target == id) continue;
            ret.push_back({ id, target });
        }

        if (curr->id != -1 && curr->id != id)
        {
            ret.push_back({ id, curr->id });
        }
    }

    vector<vector<int>> palindromePairs(vector<string>& words) 
    {
        n = words.size();

        TrieNode* root = new TrieNode();
        for (int i = 0; i < n; i++)
        {
            root->insert(words[i], i, this);
        }

        for (int i = 0; i < n; i++)
        {
            search(words[i], i, root);
        }

        return ret;
    }
};

void TrieNode::insert(const string& str, const int ID, Solution* sol)
{
    TrieNode* curr = this;

    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (sol->isPalindrome(str, 0, i))
        {
            curr->palindrome_ids.push_back(ID);
        }

        if (curr->chiled[str[i] - 'a'] == nullptr)
        {
            curr->chiled[str[i] - 'a'] = new TrieNode();
        }

        curr = curr->chiled[str[i] - 'a'];
    }

    curr->id = ID;
}

int main()
{

    return 0;
}