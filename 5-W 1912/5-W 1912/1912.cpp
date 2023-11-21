#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, sum, a, ret = -1001;

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		sum += a;
		ret = max(ret, sum);
		if (sum < 0) sum = 0;
	}

	cout << ret << "\n";

	return 0;
}