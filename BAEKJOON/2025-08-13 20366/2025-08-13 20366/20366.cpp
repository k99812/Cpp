#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> arr;

int main()
{
	cin >> n;

	arr = vector<int>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	return 0;
}