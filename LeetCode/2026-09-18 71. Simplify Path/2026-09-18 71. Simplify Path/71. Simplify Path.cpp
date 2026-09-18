#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

class Solution 
{
public:
    string simplifyPath(string path) 
    {
        stringstream ss(path);
        string temp;
        vector<string> st;

        while (getline(ss, temp, '/'))
        {
            if (temp == "" || temp == ".") continue;

            if (temp == "..")
            {
                if (!st.empty())
                {
                    st.pop_back();
                }
            }
            else
            {
                st.push_back(temp);
            }
        }

        string ret = "";
        for (const string& str : st)
        {
            ret += "/" + str;
        }

        return ret.empty() ? "/" : ret;
    }
};

int main()
{

	return 0;
}