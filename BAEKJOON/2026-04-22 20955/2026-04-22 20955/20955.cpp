#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<int> parent;

int getRoot(int num)
{
	if (parent[num] == num) return num;
	return parent[num] = getRoot(parent[num]);
}

void unionParent(int a, int b)
{
	int root_a = getRoot(a), root_b = getRoot(b);

	if (root_a != root_b)
	{
		if (root_b < root_a)
		{
			swap(root_a, root_b);
		}

		parent[root_b] = root_a;
	}
}

int main()
{
	cin >> n >> m;

	parent.assign(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	int cut_cnt = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		int root_a = getRoot(a), root_b = getRoot(b);
		if (root_a != root_b)
		{
			unionParent(root_a, root_b);
		}
		else
		{
			cut_cnt++;
		}
	}

	int add_cnt = 0, now = getRoot(1);
	for (int i = 2; i <= n; i++)
	{
		if (getRoot(i) != now)
		{
			add_cnt++;
			unionParent(now, parent[i]);
		}
	}

	cout << add_cnt + cut_cnt << "\n";

	return 0;
}