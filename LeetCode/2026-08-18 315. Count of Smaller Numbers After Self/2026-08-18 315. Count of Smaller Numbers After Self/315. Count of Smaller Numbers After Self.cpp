#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct segTree
{
    vector<int> tree, lazy;

public:
    segTree(int n)
    {
        tree.assign(4 * n + 1, 0);
    }

    int update(int node, int left, int right, int val)
    {
        if (val < left || right < val) return tree[node];

        if (left == right)
        {
            return tree[node] += 1;
        }

        int mid = left + (right - left) / 2;
        return tree[node] = update(2 * node, left, mid, val) +
            update(2 * node + 1, mid + 1, right, val);
    }

    int query(int node, int left, int right, int ql, int qr)
    {
        if (right < ql || qr < left) return 0;

        if (ql <= left && right <= qr)
        {
            return tree[node];
        }

        int mid = left + (right - left) / 2;
        return query(2 * node, left, mid, ql, qr) + 
            query(2 * node + 1, mid + 1, right, ql, qr);
    }
};

class Solution 
{
    const int OFFSET = 10000;
    const int MAX_VAL = 20000;

public:
    Solution() 
    {

    }

    vector<int> countSmaller(vector<int>& nums) 
    {
        int n = nums.size();
        segTree tree = segTree(MAX_VAL);

        vector<int> ret(n, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            int val = nums[i] + OFFSET;

            ret[i] = tree.query(1, 0, MAX_VAL, 0, val - 1);
            tree.update(1, 0, MAX_VAL, val);
        }

        return ret;
    }
};

int main()
{

	return 0;
}