#include<iostream>
#include<algorithm>

using namespace std;

int n, a[3], x, y, z, dp_min[3], dp_max[3];

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[0] >> a[1] >> a[2];

		x = dp_min[0], y = dp_min[1], z = dp_min[2];

		dp_min[0] = min(x, y) + a[0];
		dp_min[1] = min(x, min(y, z)) + a[1];
		dp_min[2] = min(y, z) + a[2];

		x = dp_max[0], y = dp_max[1], z = dp_max[2];

		dp_max[0] = max(x, y) + a[0];
		dp_max[1] = max(x, max(y, z)) + a[1];
		dp_max[2] = max(y, z) + a[2];
	}

	cout << max(dp_max[0], max(dp_max[1], dp_max[2])) << " " << min(dp_min[0], min(dp_min[1], dp_min[2])) << "\n";

	return 0;
}