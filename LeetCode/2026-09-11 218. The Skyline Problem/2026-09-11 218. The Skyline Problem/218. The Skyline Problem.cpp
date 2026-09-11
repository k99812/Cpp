#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
    {
        vector<pair<int, int>> events;

        for (const auto& b : buildings)
        {
            events.push_back({ b[0], -b[2] });
            events.push_back({ b[1], b[2] });
        }

        sort(events.begin(), events.end());

        vector<vector<int>> ret;
        multiset<int> heights;
        heights.insert(0);
        
        int prev_max = 0;

        for (auto& [x, y] : events)
        {
            if (y < 0)
            {
                heights.insert(-y);
            }
            else
            {
                heights.erase(heights.find(y));
            }

            int now_max = *heights.rbegin();

            if (now_max != prev_max)
            {
                ret.push_back({ x, now_max });
                prev_max = now_max;
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}