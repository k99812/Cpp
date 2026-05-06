#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int> ret;
        if (s.empty() || words.empty()) return ret;

        int size = words.size(), word_len = words[0].size();

        unordered_map<string, int> word_cnt;
        for (const string& str : words) word_cnt[str]++;

        for (int i = 0; i < word_len; i++)
        {
            int left = i, right = i, cnt = 0;
            unordered_map<string, int> un_map;

            while (right + word_len <= s.size())
            {
                string now = s.substr(right, word_len);
                right += word_len;

                if (word_cnt.count(now))
                {
                    un_map[now]++;
                    cnt++;

                    while (un_map[now] > word_cnt[now])
                    {
                        string left_word = s.substr(left, word_len);
                        un_map[left_word]--;
                        cnt--;
                        left += word_len;
                    }

                    if (cnt == size) ret.push_back(left);
                }
                else
                {
                    un_map.clear();
                    cnt = 0;
                    left = right;
                }
            }
        }

        return ret;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution sol = Solution();
    vector<string> input = { "foo","bar" };

    vector<int> ret = sol.findSubstring(s, input);
    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << "\n";
    }

    return 0;
}