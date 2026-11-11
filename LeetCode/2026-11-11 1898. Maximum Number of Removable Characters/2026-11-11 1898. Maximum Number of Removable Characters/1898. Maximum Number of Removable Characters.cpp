#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    bool go(int mid, const string& s, const string& p, const vector<int>& removable)
    {
        vector<int> remove(s.size(), 0);

        for (int i = 0; i < mid; i++)
        {
            remove[removable[i]] = 1;
        }

        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (remove[i]) continue;

            if (s[i] == p[j])
            {
                j++;
            }
        }

        return j >= p.size();
    }

public:
    int maximumRemovals(string s, string p, vector<int>& removable) 
    {
        int left = 0, right = removable.size(), ret = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (go(mid, s, p, removable))
            {
                ret = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}