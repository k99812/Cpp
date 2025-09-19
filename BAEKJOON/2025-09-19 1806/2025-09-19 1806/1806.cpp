#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, s;
vector<int> v;

int main()
{
	cin >> n >> s;

	v = vector<int>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int first = 0, second = 0;
	int sum = v[0], ret = 1e9;

	while(first <= second && second < n)
	{ 
		if (sum >= s)
		{
			ret = min(ret, second - first + 1);
			sum -= v[first];
			first++;
		}
		else
		{
			second++;
			if (second < n) sum += v[second];
		}
	}

	cout << (ret == 1e9 ? 0 : ret) << "\n";

	return 0;
}