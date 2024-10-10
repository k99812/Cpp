#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long n, check[100004], ret, s, e;

int main()
{
	cin >> n;
	vector<long long> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	while (e < n)
	{
		if (!check[v[e]])
		{
			check[v[e]]++;
			e++;
		}
		else
		{
			ret += (e - s);
			check[v[s]]--;
			s++;
		}
	}

	ret += (long long)(e - s) * (e - s + 1) / 2;
	cout << ret << "\n";

	return 0;
}