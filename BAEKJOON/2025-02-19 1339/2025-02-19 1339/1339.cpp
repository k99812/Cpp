#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> weight(26);

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		int len = s.length() - 1;
		for (int j = 0; j <= len; j++)
		{
			weight[s[j] - 'A'] += pow(10, len - j);
		}
	}

	sort(weight.begin(), weight.end(),
		[](const int& a, const int& b) -> bool
	{
		return a > b;
	});

	int num = 9, ret = 0;
	for (const int& i : weight)
	{
		if (!i) break;
		ret += i * num--;
	}

	cout << ret << "\n";

	return 0;
}