#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int n = gas.size();

        int total_gas = 0, total_cost = 0;
        int start_station = 0, now_gas = 0;

        for (int i = 0; i < n; i++)
        {
            total_gas += gas[i];
            total_cost += cost[i];

            now_gas += gas[i] - cost[i];

            if (now_gas < 0)
            {
                start_station = i + 1;
                now_gas = 0;
            }
        }

        if (total_gas < total_cost) return -1;

        return start_station;
    }
};

int main()
{

	return 0;
}