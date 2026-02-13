#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<pair<int, int>> arr;

int main()
{
	cin >> n;

	arr.assign(n, {});

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	return 0;
}