#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<int> parent, enemy;

int getRoot(int num)
{
	if (parent[num] == num) return num;
	return parent[num] = getRoot(parent[num]);
}

void unionParent(int a, int b)
{
	int parent_a = getRoot(a), parent_b = getRoot(b);

	if (parent_a != parent_b)
	{
		if (parent_a > parent_b) swap(parent_a, parent_b);

		parent[parent_b] = parent_a;
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

	parent.assign(n + 1, 0);
	enemy.assign(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		char c;
		int p, q;
		cin >> c >> p >> q;

		if (c == 'F')
		{
			unionParent(p, q);
		}
		else
		{
			if (enemy[p] == 0) enemy[p] = q;
			else unionParent(enemy[p], q);

			if (enemy[q] == 0) enemy[q] = p;
			else unionParent(enemy[q], p);
		}
	}

	int team = 0;
	for (int i = 1; i <= n; i++)
	{
		if (parent[i] == i) team++;
	}

	cout << team << "\n";

	return 0;
}