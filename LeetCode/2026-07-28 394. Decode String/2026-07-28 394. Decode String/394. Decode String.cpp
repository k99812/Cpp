#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

class Solution 
{
public:
    string decodeString(string s) 
    {
        vector<int> numStack;
        vector<string> strStack;

        string str = "";
        int now = 0;

        for (const char c : s)
        {
            if (isdigit(c))
            {
                now = now * 10 + (c - '0');
            }
            else if (c == '[')
            {
                numStack.push_back(now);
                strStack.push_back(str);

                now = 0;
                str = "";
            }
            else if (c == ']')
            {
                int n = numStack.back();
                numStack.pop_back();

                string now_str = strStack.back();
                strStack.pop_back();
                
                for (int i = 0; i < n; i++)
                {
                    now_str += str;
                }

                str = now_str;
            }
            else
            {
                str += c;
            }
        }

        return str;
    }
};

int main()
{

    return 0;
}