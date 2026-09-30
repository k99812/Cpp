#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
    int lastStoneWeightII(vector<int>& stones) 
    {
        int sum = 0;
        for (int weight : stones) sum += weight;

        int target = sum / 2;
        vector<int> dp(target + 1, 0);

        for (int weight : stones)
        {
            for (int i = target; i >= weight; i--)
            {
                dp[i] = max(dp[i], dp[i - weight] + weight);
            }
        }

        return (sum - dp[target]) - dp[target];
    }
};

int main()
{

	return 0;
}