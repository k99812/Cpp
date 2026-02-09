#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, l, r, x;
vector<int> arr;

int main()
{
	cin >> n >> l >> r >> x;

	arr.assign(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	return 0;
}	