#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;

int getRoot(int num, vector<int>& parents)
{
	if (num == parents[num]) return num;
	return parents[num] = getRoot(parents[num], parents);
}

void unionParent(int a, int b, vector<int>& parents)
{
	int par_a = getRoot(a, parents), par_b = getRoot(b, parents);
	if (par_a != par_b)
	{
		parents[par_a] = par_b;
	}
}

bool find(int a, int b, vector<int>& parents)
{
	int par_a = getRoot(a, parents), par_b = getRoot(b, parents);
	if (par_a == par_b) return true;
	return false;
}

int main()
{
	cin >> n >> m;
	vector<int> parents(n + 1);
	vector<int> plan(n + 1);

	for (int i = 1; i <= n; i++)
	{
		parents[i] = i;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int temp;
			cin >> temp;

			if (temp)
			{
				unionParent(i, j, parents);
			}
		}
	}

	int root;
	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;

		if (!i) root = getRoot(temp, parents);
		else
		{
			if (getRoot(root, parents) != getRoot(temp, parents))
			{
				cout << "NO\n";
				return 0;
			}
		}
	}

	cout << "YES\n";

	return 0;
}