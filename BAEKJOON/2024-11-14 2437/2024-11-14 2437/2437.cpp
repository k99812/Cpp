#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, sum = 1;

int main()
{
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		if (v[i] > sum) break;
		sum += v[i];
	}

	cout << sum << "\n";

	return 0;
}