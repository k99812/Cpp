#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int t, n, m;

int BinarySerch(int num, const vector<int>& InV1)
{
	int low = 0, hi = InV1.size() - 1, mid;

	while (low <= hi)
	{
		mid = (low + hi) / 2;

		if (InV1[mid] < num)
		{
			low = mid + 1;
		}
		else if (InV1[mid] > num)
		{
			hi = mid - 1;
		}
		else return 1;
	}

	return 0;
}

int main()
{
	cin >> t;

	while (t--)
	{
		cin >> n;
		vector<int> v1(n);
		for (int i = 0; i < n; i++) cin >> v1[i];

		cin >> m;
		vector<int> v2(m);
		for (int i = 0; i < m; i++) cin >> v2[i];

		sort(v1.begin(), v1.end());

		for (int i = 0; i < m; i++)
		{
			cout << BinarySerch(v2[i], v1) << "\n";
		}
	}

	return 0;
}