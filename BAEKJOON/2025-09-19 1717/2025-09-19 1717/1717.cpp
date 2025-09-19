#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<int> parent;

int getRoot(int num)
{
	if (num == parent[num]) return parent[num];
	return parent[num] = getRoot(parent[num]);
}

void unionParent(int a, int b)
{
	int parent_a = getRoot(a), parent_b = getRoot(b);

	if (parent_a != parent_b)
	{
		if (parent_a < parent_b)
		{
			parent[parent_b] = parent_a;
		}
		else
		{
			parent[parent_a] = parent_b;
		}
	}
}

bool find(int a, int b)
{
	int parent_a = getRoot(a), parent_b = getRoot(b);

	return parent_a == parent_b;
}

int main()
{
	cin >> n >> m;
	parent = vector<int>(n + 1);

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int t, a, b;
		cin >> t >> a >> b;

		if (t)
		{
			cout << (find(a, b) ? "YES" : "NO") << "\n";
		}
		else
		{
			unionParent(a, b);
		}
	}

	return 0;
}