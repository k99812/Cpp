#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

class Solution 
{
public:
    string removeKdigits(string num, int k) 
    {
        int n = num.size();

        string s = "";

        for (int i = 0; i < n; i++)
        {
            while (s.size() && s.back() > num[i] && k > 0)
            {
                k--;
                s.pop_back();
            }

            if (s.empty() && num[i] == '0') continue;

            s.push_back(num[i]);
        }

        while (s.size() && k > 0)
        {
            s.pop_back();
            k--;
        }

        return s.empty() ? "0" : s;
    }
};

int main()
{

	return 0;
}