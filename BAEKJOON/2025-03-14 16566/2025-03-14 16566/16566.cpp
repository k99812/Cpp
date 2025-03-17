#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, k;

int getRoot(int num, vector<int>& parent)
{
	if (parent[num] == num) return num;
	return parent[num] = getRoot(parent[num], parent);
}

void unionParent(int a, int b, vector<int>& parent)
{
	int parent_a = getRoot(a, parent), parent_b = getRoot(b, parent);
	if (parent_a < parent_b)
	{
		parent[parent_a] = parent_b;
	}
	else
	{
		parent[parent_b] = parent_a;
	}
}

int main()
{
	cin >> n >> m >> k;

	vector<int> card(m), parent(m + 1);

	for (int i = 0; i < m; i++)
	{
		parent[i] = i;
	}

	for (int& i : card)
	{
		cin >> i;
	}

	sort(card.begin(), card.end());

	for (int i = 0; i < k; i++)
	{
		int num;
		cin >> num;

		int index = lower_bound(card.begin(), card.end(), num + 1) - card.begin();
		cout << card[getRoot(index, parent)] << "\n";

		if (index < m - 1)
		{
			unionParent(getRoot(index, parent), getRoot(index, parent) + 1, parent);
		}
	}

	return 0;
}