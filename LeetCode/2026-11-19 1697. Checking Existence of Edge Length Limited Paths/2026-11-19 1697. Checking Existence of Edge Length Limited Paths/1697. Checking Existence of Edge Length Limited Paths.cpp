#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    struct UnionFind
    {
        vector<int> parents;

        UnionFind() {}
        UnionFind(int n)
        {
            parents.assign(n, 0);
            for (int i = 0; i < n; i++)
            {
                parents[i] = i;
            }
        }

        int getRoot(int num)
        {
            if (num == parents[num]) return num;
            return parents[num] = getRoot(parents[num]);
        }

        bool unionParent(int a, int b)
        {
            int pa_a = getRoot(a), pa_b = getRoot(b);

            if (pa_a != pa_b)
            {
                if (pa_a > pa_b)
                {
                    swap(pa_a, pa_b);
                }

                parents[pa_b] = pa_a;
                return true;
            }

            return false;
        }
    };

    struct Query
    {
        int p, q, limit, idx;

        bool operator<(const Query& other) const
        {
            return limit < other.limit;
        }
    };

public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) 
    {
        UnionFind uf(n);

        sort(edgeList.begin(), edgeList.end(),
            [](const vector<int>& a, const vector<int>& b)
        {
            return a[2] < b[2];
        });

        int q_size = queries.size();
        vector<Query> q;
        q.assign(q_size, {});

        for (int i = 0; i < q_size; i++)
        {
            q[i] = { queries[i][0], queries[i][1], queries[i][2], i };
        }

        sort(q.begin(), q.end());

        int e = 0;
        int e_size = edgeList.size();
        vector<bool> ret(q_size, false);

        for (const auto& query : q)
        {
            while (e < e_size && edgeList[e][2] < query.limit)
            {
                uf.unionParent(edgeList[e][0], edgeList[e][1]);
                e++;
            }

            ret[query.idx] = (uf.getRoot(query.p) == uf.getRoot(query.q));
        }

        return ret;
    }
};

int main()
{

	return 0;
}