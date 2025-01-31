#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, t;

int getRoot(int num, vector<int>& parent)
{
	if (num == parent[num]) return num;
	return parent[num] = getRoot(parent[num], parent);
}

void unionParent(int a, int b, vector<int>& parent)
{
	int par_a = getRoot(a, parent), par_b = getRoot(b, parent);
	if (par_a != par_b)
	{
		par_a < par_b ? parent[par_b] = par_a : parent[par_a] = par_b;
	}
}

bool findParent(int a, int b, vector<int>& parent)
{
	int par_a = getRoot(a, parent), par_b = getRoot(b, parent);

	if (par_a != par_b) return false;
	return true;
}

int main()
{
	cin >> n >> m >> t;

	vector<int> parent(n + 1);
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	vector<int> knows(t);
	for (int i = 0; i < t; i++)
	{
		cin >> knows[i];
	}

	int ret = m;
	vector<vector<int>> party(m);

	while (m--)
	{
		int num, people, prev;
		cin >> num;

		for (int i = 0; i < num; i++)
		{
			if (i >= 1)
			{
				prev = people;
				cin >> people;
				unionParent(prev, people, parent);
			}
			else
			{
				cin >> people;
			}
			party[m].push_back(people);
		}
	}

	for (const vector<int>& v : party)
	{
		bool flag = false;
		for (const int& people : v)
		{
			if (flag) break;

			for (const int& know : knows)
			{
				if (findParent(people, know, parent))
				{
					flag = true;
					break;
				}
			}
		}

		if (flag) --ret;
	}

	cout << ret << "\n";

	return 0;
}