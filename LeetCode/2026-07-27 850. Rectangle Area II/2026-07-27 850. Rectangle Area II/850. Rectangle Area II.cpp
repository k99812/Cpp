#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

#define Mod ((ll)1e9 + 7)

typedef long long ll;

struct Info
{
    int x, y1, y2, type;

    bool operator<(const Info& other) const
    {
        return x < other.x;
    }
};

struct SegTree
{
    int size;
    vector<ll> tree;
    vector<int> count;
    const vector<int>& y_coord;

    SegTree(int n, const vector<int>& arr) : y_coord(arr)
    {
        size = n;
        tree.assign(4 * size + 1, 0);
        count.assign(4 * size + 1, 0);
    }

    ll update(int node, int left, int right, int ql, int qr, int val)
    {
        if (right < ql || qr < left) return tree[node];

        if (ql <= left && right <= qr)
        {
            count[node] += val;
        }
        else
        {
            int mid = left + (right - left) / 2;
            update(2 * node, left, mid, ql, qr, val);
            update(2 * node + 1, mid + 1, right, ql, qr, val);
        }

        if (count[node] > 0)
        {
            tree[node] = y_coord[right + 1] - y_coord[left];
        }
        else
        {
            if (left == right) tree[node] = 0;
            else tree[node] = tree[2 * node] + tree[2 * node + 1];
        }

        return tree[node];
    }
};

class Solution 
{
public:
    int rectangleArea(vector<vector<int>>& rectangles) 
    {
        vector<Info> info;
        set<int> y_set;

        for (const vector<int>& rect : rectangles)
        {
            info.push_back({ rect[0], rect[1], rect[3], 1 });
            info.push_back({ rect[2], rect[1], rect[3], -1 });
            y_set.insert(rect[1]);
            y_set.insert(rect[3]);
        }

        sort(info.begin(), info.end());
        vector<int> y_coord(y_set.begin(), y_set.end());

        int n = y_coord.size() - 1;
        SegTree tree(n, y_coord);

        ll ret = 0, prev_x = info[0].x;

        for (const Info& i : info)
        {
            ret = (ret + tree.tree[1] * (i.x - prev_x)) % Mod;
            prev_x = i.x;

            int ql = lower_bound(y_coord.begin(), y_coord.end(), i.y1) - y_coord.begin();
            int qr = lower_bound(y_coord.begin(), y_coord.end(), i.y2) - y_coord.begin() - 1;

            if (ql <= qr)
            {
                tree.update(1, 0, n - 1, ql, qr, i.type);
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}