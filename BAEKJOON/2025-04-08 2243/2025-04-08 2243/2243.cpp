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

int find(int idx)
{
	int left = 1, right = tree.size() - 1, ret = MAX;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (sum(mid) < idx)
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
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	tree = vector<int>(MAX);

	while (n--)
	{
		int a, b, c;
		cin >> a;

		if (a == 1)
		{
			cin >> b;

			int Candy_idx = find(b);

			cout << Candy_idx << "\n";

			update(Candy_idx, -1);
		}
		else
		{
			cin >> b >> c;

			update(b, c);
		}
	}

	return 0;
} 