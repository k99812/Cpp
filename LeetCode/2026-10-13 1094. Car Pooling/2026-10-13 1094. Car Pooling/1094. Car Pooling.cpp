#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

class Solution 
{
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        map<int, int> passenger;

        for (const vector<int>& trip : trips)
        {
            int cost = trip[0], from = trip[1], to = trip[2];

            passenger[from] += cost;
            passenger[to] -= cost;
        }

        int now = 0;
        for (const auto& [stop, cost] : passenger)
        {
            now += cost;

            if (now > capacity) return false;
        }

        return true;
    }
};

int main()
{

	return 0;
}