#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

class Solution 
{
    string begin, end;
    vector<string> wordList;

public:
    Solution() : begin(""), end("")
    {

    }

    int ladderLength(string beginWord, string endWord, vector<string>& input) 
    {
        begin = move(beginWord);
        end = move(endWord);
        wordList = move(input);
    }
};

int main()
{
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = { "hot", "dot", "dog", "lot", "log", "cog" };

    Solution sol = Solution();
    cout << sol.ladderLength(beginWord, endWord, wordList) << "\n";

	return 0;
}