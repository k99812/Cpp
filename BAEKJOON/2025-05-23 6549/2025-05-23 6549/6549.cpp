#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> v, segTree;

int main()
{
	while (cin >> n && n != 0)
	{
		v = vector<int>(n);
		segTree = vector<int>(4 * n);

		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
	}

	return 0;
}