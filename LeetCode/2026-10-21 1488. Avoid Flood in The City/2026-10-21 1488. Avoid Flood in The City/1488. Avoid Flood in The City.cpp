#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    vector<int> avoidFlood(vector<int>& rains) 
    {
        int n = rains.size();
        vector<int> ret(n, 1);

        unordered_map<int, int> lake;
        set<int> sunny;
        
        for (int i = 0; i < n; i++)
        {
            int rain = rains[i];

            if (rain == 0)
            {
                sunny.insert(i);
            }
            else
            {
                ret[i] = -1;

                if (lake.find(rain) != lake.end())
                {
                    int idx = lake[rain];

                    auto itr = sunny.lower_bound(idx);

                    if (itr == sunny.end()) return {};

                    int sun_idx = *itr;
                    ret[sun_idx] = rain;

                    sunny.erase(itr);
                }

                lake[rain] = i;
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}