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
            area = max(area, min(height[left], height[right]) * (right - left));

            if (height[left] <= height[right])
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
    vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };

    Solution sol = Solution();
    cout << sol.maxArea(height) << "\n";

	return 0;
}