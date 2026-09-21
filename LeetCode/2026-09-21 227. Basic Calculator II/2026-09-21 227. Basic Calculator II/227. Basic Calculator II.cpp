#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

class Solution 
{
public:
    int calculate(string s) 
    {
        int num = 0, n = s.size();
        vector<int> st;
        char op = '+';

        for (int i = 0; i < n; i++)
        {
            char c = s[i];

            if (isdigit(c))
            {
                num = num * 10 + (c - '0');
            }
            
            if ((!isdigit(c) && c != ' ') || i == n - 1)
            {
                if (op == '+')
                {
                    st.push_back(num);
                }
                else if (op == '-') 
                { 
                    st.push_back(-num); 
                }
                else if (op == '*')
                {
                    int& prev = st.back();
                    prev = prev * num;
                }
                else if (op == '/')
                {
                    int& prev = st.back();
                    prev = prev / num;
                }

                num = 0;
                op = c;
            }
        }

        int ret = 0;
        for (int i : st)
        {
            ret += i;
        }

        return ret;
    }
};

int main()
{

	return 0;
}