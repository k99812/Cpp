#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    typedef long long ll;

    int n;
    vector<int> nums1, nums2, segTree, lazy;

    int init(int node, int left, int right)
    {
        if (left == right)
        {
            return segTree[node] = nums1[left];
        }

        int mid = (left + right) / 2;
        return segTree[node] = init(2 * node, left, mid) + init(2 * node + 1, mid + 1, right);
    }

    void push(int node, int left, int right)
    {
        if (lazy[node])
        {
            int mid = (left + right) / 2;

            segTree[node * 2] = (mid - left + 1) - segTree[node * 2];
            lazy[node * 2] ^= 1;

            segTree[node * 2 + 1] = (right - mid) - segTree[node * 2 + 1];
            lazy[node * 2 + 1] ^= 1;

            lazy[node] = 0;
        }
    }

    int update(int node, int left, int right, int start, int end)
    {
        if (right < start || end < left) return segTree[node];

        if (start <= left && right <= end)
        {
            lazy[node] ^= 1;
            return segTree[node] = (right - left + 1) - segTree[node];
        }

        push(node, left, right);

        int mid = (left + right) / 2;
        return segTree[node] = update(2 * node, left, mid, start, end) + update(2 * node + 1, mid + 1, right, start, end);
    }

public:
    Solution() : n(0)
    {

    }

    vector<long long> handleQuery(vector<int>& inNums1, vector<int>& inNums2, vector<vector<int>>& queries) 
    {
        nums1 = move(inNums1);
        nums2 = move(inNums2);
        n = nums1.size();

        segTree.assign(4 * n + 1, 0);
        lazy.assign(4 * n + 1, 0);

        init(1, 0, n - 1);

        ll sum = 0;
        for (int num : nums2)
        {
            sum += num;
        }

        vector<ll> ret;
        for (const vector<int>& q : queries)
        {
            int type = q[0];

            switch (type)
            {
            case 1:
            {
                int l = q[1], r = q[2];
                update(1, 0, n - 1, l, r);
                break;
            }
            case 2:
            {
                ll p = q[1];
                ll total_one = segTree[1];
                sum += p * total_one;
                break;
            }
            case 3:
            {
                ret.push_back(sum);
                break;
            }
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}