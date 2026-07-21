#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class NumArray 
{
private:
    int n;
    vector<int> tree, lazy, arr;

    int init(int node, int left, int right)
    {
        if (left == right)
        {
            return tree[node] = arr[left];
        }

        int mid = left + (right - left) / 2;
        return tree[node] = init(2 * node, left, mid) + init(2 * node + 1, mid + 1, right);
    }

    void push(int node, int left, int right)
    {
        if (lazy[node])
        {
            int mid = left + (right - left) / 2;

            tree[2 * node] += (mid - left + 1) * lazy[node];
            lazy[2 * node] += lazy[node];

            tree[2 * node + 1] += (right - mid) * lazy[node];
            lazy[2 * node + 1] += lazy[node];

            lazy[node] = 0;
        }
    }

    int tree_update(int node, int left, int right, int ql, int qr, int val)
    {
        if (right < ql || qr < left) return tree[node];

        if (ql <= left && right <= qr)
        {
            lazy[node] += val;
            return tree[node] += (right - left + 1) * val;
        }

        push(node, left, right);

        int mid = left + (right - left) / 2;
        return tree[node] = tree_update(2 * node, left, mid, ql, qr, val) +
            tree_update(2 * node + 1, mid + 1, right, ql, qr, val);
    }

    int query(int node, int left, int right, int ql, int qr)
    {
        if (right < ql || qr < left) return 0;

        if (ql <= left && right <= qr)
        {
            return tree[node];
        }

        push(node, left, right);

        int mid = left + (right - left) / 2;
        return query(2 * node, left, mid, ql, qr) + query(2 * node + 1, mid + 1, right, ql, qr);
    }

public:
    NumArray(vector<int>& nums) 
    {
        n = nums.size();
        arr = move(nums);
        tree.assign(4 * n + 1, 0);
        lazy.assign(4 * n + 1, 0);

        init(1, 0, n - 1);
    }

    void update(int index, int val) 
    {
        int diff = val - arr[index];
        arr[index] = val;

        tree_update(1, 0, n - 1, index, index, diff);
    }

    int sumRange(int left, int right) 
    {
        return query(1, 0, n - 1, left, right);
    }
};

int main()
{

	return 0;
}