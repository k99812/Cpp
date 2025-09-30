#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n;
vector<string> arr;

int main()
{
	cin >> n;

	arr = vector<string>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	return 0;
}