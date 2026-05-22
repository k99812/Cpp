#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    int n;
    vector<int> height, seg;

    int init(int node, int start, int end)
    {
        if (start == end)
        {
            return seg[node] = height[start];
        }

        int mid = (start + end) / 2;
        return seg[node] = max(init(2 * node, start, mid), init(2 * node + 1, mid + 1, end));
    }

    int search(int node, int start, int end, int left, int right)
    {
        if (right < start || end < left) return 0;

        if (left <= start && end <= right) return seg[node];

        int mid = (start + end) / 2;
        return max(search(2 * node, start, mid, left, right), 
            search(2 * node + 1, mid + 1, end, left, right));
    }

public:
    Solution() : n(0)
    {

    }

    int segtrap(vector<int>& input) 
    {
        height = move(input);
        n = height.size();

        if (n <= 2) return 0;

        seg.assign(4 * n, 0);

        init(1, 0, n - 1);

        int ret = 0;

        for (int i = 1; i < n - 1; i++)
        {
            int left_max = search(1, 0, n - 1, 0, i);
            int right_max = search(1, 0, n - 1, i, n - 1);

            ret += min(left_max, right_max) - height[i];
        }

        return ret;
    }

    int trap(vector<int>& input)
    {
        height = move(input);
        n = height.size();

        if (n <= 2) return 0;

        int left = 0, right = n - 1;

        int left_max = height[left], right_max = height[right];
        int ret = 0;

        while (left < right)
        {
            if (left_max <= right_max)
            {
                left++;
                left_max = max(left_max, height[left]);
                ret += left_max - height[left];
            }
            else
            {
                right--;
                right_max = max(right_max, height[right]);
                ret += right_max - height[right];
            }
        }

        return ret;
    }
};

int main()
{
    vector<int> height = { 4, 2, 0, 3, 2, 5 };

    Solution sol = Solution();
    cout << sol.trap(height) << "\n";

	return 0;
}