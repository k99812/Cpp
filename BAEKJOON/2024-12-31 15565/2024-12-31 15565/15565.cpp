#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for(int i=0; i<n; i++)
	{
		cin >> v[i];
	}

	int first = 0, second = 0, cnt = 0, ret = INT32_MAX;
	while (second < n)
	{
		while (cnt < k && second < n)
		{
			if (v[second] == 1) cnt++;
			second++;
		}

		while (cnt == k)
		{
			ret = min(ret, second - first);
			if (v[first] == 1) cnt--;
			first++;
			cout << "first : " << first << " second : " << second << "\n";
		}
	}
	
	cout << (ret == INT32_MAX ? -1 : ret) << "\n";

	return 0;
}