#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    vector<int> canSeePersonsCount(vector<int>& heights) 
    {
        int n = heights.size();
        vector<int> st;
        vector<int> ret(n, 0);

        for (int i = 0; i < n; i++)
        {
            while (st.size() && heights[st.back()] < heights[i])
            {
                ret[st.back()]++;
                st.pop_back();
            }

            if (st.size())
            {
                ret[st.back()]++;
            }

            st.push_back(i);
        }

        return ret;
    }
};

int main()
{

	return 0;
}