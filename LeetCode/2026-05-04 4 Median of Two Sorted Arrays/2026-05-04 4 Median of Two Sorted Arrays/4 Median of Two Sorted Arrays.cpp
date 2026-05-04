#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    int n = 0, m = 0;
    vector<int> arr;

    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;

    void addNum(int num)
    {
        if (max_pq.size() == min_pq.size())
        {
            max_pq.push(num);
        }
        else
        {
            min_pq.push(num);
        }

        if (min_pq.size() && max_pq.top() > min_pq.top())
        {
            int left_val = max_pq.top(); max_pq.pop();
            int right_val = min_pq.top(); min_pq.pop();

            min_pq.push(left_val);
            max_pq.push(right_val);
        }
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        n = nums2.size(), m = nums1.size();

        for (const int num : nums1) addNum(num);
        for (const int num : nums2) addNum(num);

        if (max_pq.size() == min_pq.size())
        {
            return (max_pq.top() + min_pq.top()) / 2.0;
        }
        else
        {
            return max_pq.top();
        }
    }
};

int main()
{
    int n, m;
    cin >> m >> n;

    vector<int> arr1(m, 0), arr2(n, 0);

    for (int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }

    Solution sol = Solution();

    double ret = sol.findMedianSortedArrays(arr1, arr2);

    cout << ret << "\n";

    return 0;
}