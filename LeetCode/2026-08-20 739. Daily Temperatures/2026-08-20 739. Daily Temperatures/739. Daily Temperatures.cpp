#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& t) 
    {
        int n = t.size();

        vector<int> stack;
        vector<int> ret(n, 0);

        for (int i = 0; i < n; i++)
        {
            while (stack.size() && t[stack.back()] < t[i])
            {
                ret[stack.back()] = i - stack.back();
                stack.pop_back();
            }

            stack.push_back(i);
        }

        return ret;
    }
};

int main()
{

	return 0;
}