#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int che[4000001], a[2000001];
int n, low, hi, ret, sum, p;

int main()
{
	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		if (che[i]) continue;
		for (int j = 2 * i; j <= n; j += i)
		{
			che[j] = 1;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (!che[i]) a[p++] = i;
	}

	while (true)
	{
		if (sum >= n) sum -= a[low++];
		else if (hi == p) break;
		else sum += a[hi++];
		if (sum == n) ret++;
	}

	cout << ret << "\n";

	return 0;
}