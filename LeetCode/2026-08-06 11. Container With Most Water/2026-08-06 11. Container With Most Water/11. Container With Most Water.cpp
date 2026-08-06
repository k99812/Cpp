#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution
{
    int n;
    vector<int> height;

public:
    Solution() : n(0)
    {

    }

    int maxArea(vector<int>& input)
    {
        height = move(input);
        n = height.size();

        int left = 0, right = n - 1, area = 0;
        while (left < right)
        {
            area = max(area, min(height[left], height[right]) * abs(left - right));

            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return area;
    }
};

int main()
{

    return 0;
}