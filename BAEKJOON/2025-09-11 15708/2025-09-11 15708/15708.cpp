#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, t, p;
vector<int> rock;

int main()
{
	cin >> n >> t >> p;
	rock = vector<int>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> rock[i];
	}

	return 0;
}