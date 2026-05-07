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

        int str_length = words[0].length(), words_size = words.size();

        unordered_map<string, int> words_cnt;
        for (const string& str : words) words_cnt[str]++;

        for (int i = 0; i < str_length; i++)
        {
            int left = i, right = i, cnt = 0;

            unordered_map<string, int> un_map;

            while (right + str_length <= s.length())
            {
                string now = s.substr(right, str_length);
                right += str_length;

                if (words_cnt.count(now))
                {
                    cnt++;
                    un_map[now]++;

                    while (un_map[now] > words_cnt[now])
                    {
                        string left_word = s.substr(left, str_length);
                        cnt--;
                        un_map[left_word]--;
                        left += str_length;
                    }

                    if (cnt == words_size) ret.push_back(left);
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