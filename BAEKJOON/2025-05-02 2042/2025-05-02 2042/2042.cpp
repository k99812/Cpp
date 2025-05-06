#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n, m, k, a, b;
vector<ll> arr, segTree;

ll init(int node, int start, int end)
{
    if (start == end)
    {
        return segTree[node] = arr[start];
    }

    int mid = (start + end) / 2;
    return segTree[node] = init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end);
}

void update(int node, int start, int end, int idx, ll diff)
{
    if (idx < start || idx > end) return;

    segTree[node] += diff;

    if (start != end) 
    {
        int mid = (start + end) / 2;
        update(2 * node, start, mid, idx, diff);
        update(2 * node + 1, mid + 1, end, idx, diff);
    }
}

ll query(int node, int start, int end, int l, int r)
{
    if (r < start || l > end) return 0;

    if (l <= start && end <= r) return segTree[node];

    int mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}

int main()
{
    cin >> n >> m >> k;

    arr.resize(n + 1);
    segTree.resize(4 * n);

    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }

    init(1, 1, n);

    for (int i = 0; i < m + k; ++i)
    {
        cin >> a >> b;

        if (a == 1)
        {
            ll c;
            cin >> c;
            ll diff = c - arr[b];
            arr[b] = c;
            update(1, 1, n, b, diff);
        }
        else
        {
            int c;
            cin >> c;
            cout << query(1, 1, n, b, c) << "\n";
        }
    }

    return 0;
}