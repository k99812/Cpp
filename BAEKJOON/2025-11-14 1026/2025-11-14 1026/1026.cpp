#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;

int main()
{
	cin >> n;

	vector<int> a(n), b(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}

	return 0;
}