#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;

struct TrieNode
{
    TrieNode* children[26]; 
    string word;

    TrieNode() : children(), word("")
    {

    }

public:
    void insert(const string& s)
    {
        TrieNode* curr = this;

        for (char c : s)
        {
            if (curr->children[c - 'a'] == nullptr)
            {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->word = s;
    }
};

class Solution 
{
    const int dy[4] = { -1, 0, 1, 0 };
    const int dx[4] = { 0, 1, 0, -1 };

    int n, m;
    vector<vector<char>> board;
    vector<string> ret;

    void dfs(int y, int x, TrieNode* node)
    {
        char c = board[y][x];

        if (c == '#' || node->children[c - 'a'] == nullptr) return;

        node = node->children[c - 'a'];

        if (node->word != "")
        {
            ret.push_back(node->word);
            node->word = "";
        }

        board[y][x] = '#';

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i], nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

            dfs(ny, nx, node);
        }

        board[y][x] = c;
    }

public:
    Solution() : n(0), m(0)
    {

    }

    vector<string> findWords(vector<vector<char>>& input_board, vector<string>& words) 
    {
        board = move(input_board);
        n = board.size(), m = board[0].size();

        TrieNode* root = new TrieNode();
        for (const string& word : words)
        {
            root->insert(word);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dfs(i, j, root);
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}