#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int getRoot(int num, vector<int>& parents)
{
	if (num == parents[num]) return num;
	return parents[num] = getRoot(parents[num], parents);
}

void unionParent(int a, int b, vector<int>& parents)
{
	int parent_a = getRoot(a, parents), parent_b = getRoot(b, parents);
	if (parent_a != parent_b)
	{
		parents[parent_a] = parent_b;
	}
}

int main()
{
	int G, P;

	cin >> G >> P;
	vector<int> parents(G + 1);

	for (int i = 1; i <= G; i++)
	{
		parents[i] = i;
	}

	int ret = 0;
	for (int i = 0; i < P; i++)
	{
		int num;
		cin >> num;

		if (!getRoot(num, parents)) break;
		else
		{
			ret++;
			unionParent(getRoot(num, parents), getRoot(num, parents) - 1, parents);
		}
	}

	cout << ret << "\n";

	return 0;
}