#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, k;
vector<int> v;

int main()
{
	cin >> n >> k;

	v = vector<int>(n);

	for (int& i : v)
	{
		cin >> i;
	}

	int first = 0, second = 0, ret = 0, sum = 0;;

	while (first < n)
	{
		while (second - first < k)
		{
			sum += v[second % n];
			second++;
		}

		ret = max(ret, sum);
		sum -= v[first];
		first++;
	}

	cout << ret << "\n";

	return 0;
}