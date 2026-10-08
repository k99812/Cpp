#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    int mctFromLeafValues(vector<int>& arr) 
    {
        int ret = 0;
        vector<int> stack;
        
        for (int num : arr)
        {
            while (stack.size() && stack.back() <= num)
            {
                int n = stack.back();
                stack.pop_back();

                if (stack.empty())
                {
                    ret += n * num;
                }
                else
                {
                    ret += n * min(stack.back(), num);
                }
            }

            stack.push_back(num);
        }

        for (int i = 1; i < stack.size(); i++)
        {
            ret += stack[i] * stack[i - 1];
        }

        return ret;
    }
};

int main()
{

	return 0;
}