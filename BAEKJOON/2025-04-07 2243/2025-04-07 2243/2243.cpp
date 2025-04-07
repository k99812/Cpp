#include<iostream>
#include<algorithm>
#include<vector>

#define MAX 1000001

using namespace std;

int n;
vector<int> tree;

void update(int idx, int num)
{
	while (idx < tree.size())
	{
		tree[idx] += num;
		idx += (idx & -idx);
	}
}

int sum(int idx)
{
	int ret = 0;

	while (idx > 0)
	{
		ret += tree[idx];
		idx -= (idx & -idx);
	}

	return ret;
}

int find(int num)
{
	int left = 1, right = tree.size() - 1, ret = MAX;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (sum(mid) < num)
		{
			left = mid + 1;
		}
		else
		{
			ret = min(ret, mid);
			right = mid - 1;
		}
	}

	return ret;
}

int main()
{
	cin >> n;

	tree = vector<int>(MAX);

	while (n--)
	{
		int a, b, c;
		cin >> a;

		if (a == 1)
		{
			cin >> b;

			int idx = find(b);

			cout << idx << "\n";

			update(idx, -1);
		}
		else
		{
			cin >> b >> c;
			update(b, c);
		}
	}

	return 0;
}