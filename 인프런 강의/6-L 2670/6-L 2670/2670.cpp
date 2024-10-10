#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
double ret, temp;

int main()
{
	cin >> n;
	vector<double> v(n);

	for (int i = 0; i < n; i++) cin >> v[i];

	temp = v[0];

	for (int i = 1; i < n; i++)
	{
		if (v[i] > temp * v[i]) temp = v[i];
		else temp *= v[i];
		ret = max(ret, temp);
	}

	cout << fixed;
	cout.precision(3);
	cout << ret + 0.00001 << "\n";

	return 0;
}