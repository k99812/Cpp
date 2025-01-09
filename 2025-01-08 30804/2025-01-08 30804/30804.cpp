#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main()
{
	int n;
	cin >> n;

	map<int, int> fruits;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int first = 0, second = 0, ret = 0, kind = 0;
	while (second < n)
	{
		while (second < n)
		{
			if (!fruits[v[second]] && kind == 2) break;
			if (!fruits[v[second++]]++) kind++;
		}

		ret = max(ret, second - first);

		if (first < second && kind == 2)
		{
			if (!--fruits[v[first++]]) kind--;
		}
	}

	cout << ret << "\n";

	return 0;
}