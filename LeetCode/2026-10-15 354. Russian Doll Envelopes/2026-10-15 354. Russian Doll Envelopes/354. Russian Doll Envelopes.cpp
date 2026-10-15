#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        int n = envelopes.size();

        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b)
        {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        vector<int> lis;

        for (int i = 0; i < n; i++)
        {
            int h = envelopes[i][1];
            auto itr = lower_bound(lis.begin(), lis.end(), h);

            if (itr == lis.end())
            {
                lis.push_back(h);
            }
            else
            {
                *itr = h;
            }
        }

        return lis.size();
    }
};

int main()
{

    return 0;
}