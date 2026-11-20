#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, q;

struct Node
{
	int p, q, r;

	bool operator<(const Node& other) const
	{
		return r > other.r;
	}
};

struct Que
{
	int k, v, idx;

	bool operator<(const Que& other) const
	{
		return k > other.k;
	}
};

struct UnionFind
{
	vector<int> parents, size;

	UnionFind() {}
	UnionFind(int n)
	{
		size.assign(n + 1, 1);
		parents.assign(n + 1, 0);

		for (int i = 1; i <= n; i++)
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
		int pa = getRoot(a), pb = getRoot(b);
		if (pa != pb)
		{
			if (pa > pb)
			{
				swap(pa, pb);
			}

			parents[pb] = pa;
			size[pa] += size[pb];
			return true;
		}

		return false;
	}
};

int main()
{
	cin >> n >> q;

	vector<Node> edge(n - 1);

	for (int i = 0; i < n - 1; i++)
	{
		cin >> edge[i].p >> edge[i].q >> edge[i].r;
	}

	vector<Que> qu(q);

	for (int i = 0; i < q; i++)
	{
		cin >> qu[i].k >> qu[i].v;
		qu[i].idx = i;
	}

	sort(edge.begin(), edge.end());
	sort(qu.begin(), qu.end());

	int i = 0;
	UnionFind uf(n);
	vector<int> ret(q, 0);

	for (const auto& [k, v, idx] : qu)
	{
		while (i < n - 1 && edge[i].r >= k)
		{
			uf.unionParent(edge[i].p, edge[i].q);
			i++;
		}

		ret[idx] = uf.size[uf.getRoot(v)] - 1;
	}

	for (int ans : ret)
	{
		cout << ans << "\n";
	}

	return 0;
}