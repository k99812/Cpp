#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int>& heights)
    {
        heights.push_back(0);

        int n = heights.size();
        vector<int> st;
        int ret = 0;

        for (int i = 0; i < n; i++)
        {
            while (st.size() && heights[st.back()] > heights[i])
            {
                int h = heights[st.back()];
                st.pop_back();

                int w = st.empty() ? i : (i - st.back() - 1);

                ret = max(ret, h * w);
            }

            st.push_back(i);
        }

        return ret;
    }
};

class Solution 
{
    const int INF = 1e9;

    int n;
    vector<int> tree, heights;

    int getMinIdx(int i, int j)
    {
        if (i == -1) return j;
        if (j == -1) return i;
        return heights[i] <= heights[j] ? i : j;
    }

    int init(int node, int left, int right)
    {
        if (left == right)
        {
            return tree[node] = left;
        }

        int mid = left + (right - left) / 2;
        return tree[node] = getMinIdx(init(2 * node, left, mid), init(2 * node + 1, mid + 1, right));
    }

    int query(int node, int left, int right, int lq, int rq)
    {
        if (rq < left || right < lq) return -1;

        if (lq <= left && right <= rq) return tree[node];

        int mid = left + (right - left) / 2;
        return getMinIdx(query(2 * node, left, mid, lq, rq), query(2 * node + 1, mid + 1, right, lq, rq));
    }

    int go(int left, int right)
    {
        if (left > right) return 0;
        if (left == right) return heights[left];

        int idx = query(1, 0, n - 1, left, right);
        int val = heights[idx], ret = (right - left + 1) * val;

        int l_bound = idx - 1;
        while (l_bound >= left && heights[l_bound] == val) l_bound--;

        int r_bound = idx + 1;
        while (r_bound <= right && heights[r_bound] == val) r_bound++;

        ret = max({ ret, go(left, l_bound), go(r_bound, right) });
        
        return ret;
    }

public:
    int largestRectangleArea(vector<int>& heights) 
    {
        n = heights.size();
        this->heights = move(heights);
        tree.assign(4 * n + 1, {});

        init(1, 0, n - 1);

        return go(0, n - 1);
    }
};

int main()
{

	return 0;
}