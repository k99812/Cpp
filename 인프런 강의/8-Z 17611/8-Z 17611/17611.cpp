#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, x, y, Y[1000004], X[1000004], ret;
pair<int, int> a[100004];
vector<int> check_x, check_y;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		x += 500000;
		y += 500000;

		a[i] = { x, y };
		check_x.push_back(x);
		check_y.push_back(y);
	}

	a[n] = a[0];

	for (int i = 0; i < n; i++)
	{
		int x1 = a[i].first, y1 = a[i].second;
		int x2 = a[i + 1].first, y2 = a[i + 1].second;

		if (x1 != x2)
		{
			if (x1 > x2)
			{
				swap(x1, x2);
			}

			for (int j = x1 + 1; j <= x2; j++)
			{
				X[j]++;
			}
		}

		if (y1 != y2) 
		{
			if (y1 > y2)
			{
				swap(y1, y2);
			}

			for (int j = y1 + 1; j <= y2; j++) 
			{
				Y[j]++;
			}
		}
	}

	for (int a : check_y) ret = max(ret, Y[a]);
	for (int a : check_x) ret = max(ret, X[a]);

	cout << ret << "\n";

	return 0;
}