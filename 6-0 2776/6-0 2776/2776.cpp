#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int t, n, m, temp;

int check(int temp, vector<int>& v)
{
	int low = 0, high = v.size() - 1, mid;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (v[mid] > temp) high = mid - 1;
		else if (v[mid] == temp) return 1;
		else low = mid + 1;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;

	while (t--)
	{
		cin >> n;
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			v.push_back(temp);
		}

		sort(v.begin(), v.end());

		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> temp;
			cout << check(temp, v) << "\n";
		}
	}

	return 0;
}