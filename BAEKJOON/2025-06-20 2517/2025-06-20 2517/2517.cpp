#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int n;
vector<ll> arr, segTree;

int main()
{
	cin >> n;

	arr = vector<ll>(n);
	segTree = vector<ll>(4 * n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	return 0;
}