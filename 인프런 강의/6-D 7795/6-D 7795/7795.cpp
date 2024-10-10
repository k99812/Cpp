#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int t, n, m, ret;

int main()
{
	cin >> t;
	
	while (t--)
	{
		cin >> n >> m;
		vector<int> a(n), b(m);
		ret = 0;

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		for (int i = 0; i < n; i++)
		{
			vector<int>::iterator pos = lower_bound(b.begin(), b.end(), a[i]);
			ret += (int)(pos - b.begin());
		}

		cout << ret << "\n";
	}
	
	return 0;
}