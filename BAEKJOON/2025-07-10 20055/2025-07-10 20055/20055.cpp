#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, k;
vector<int> v;

int main()
{
	cin >> n >> k;

	v = vector<int>(2 * n);

	for (int i = 0; i < 2 * n; i++)
	{
		cin >> v[i];
	}

	return 0;
}