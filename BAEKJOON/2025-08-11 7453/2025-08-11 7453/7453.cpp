#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> a, b, c, d;

int main()
{
	cin >> n;

	a = b = c = d = vector<int>(n);

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	return 0;
}