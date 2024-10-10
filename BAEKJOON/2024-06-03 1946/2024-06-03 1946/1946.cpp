#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int T, n;

int main()
{
	cin >> T;

	while (T--)
	{
		int ret = 1;
		vector<pair<int, int>> v;

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			v.push_back({ a, b });
		}
		 
		sort(v.begin(), v.end());

		int temp = 0;

		for (int i = 1; i < n; i++)
		{
			if (v[temp].second > v[i].second)
			{
				ret++;
				temp = i;
			}
		}

		cout << ret << "\n";
	}

	return 0;
}