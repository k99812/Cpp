#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<unordered_map>

using namespace std;

int main()
{
	int n;
	cin >> n;

	unordered_map<char, int> map;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		int len = s.length() - 1;
		for (int j = 0; j <= len; j++)
		{
			map[s[j]] += pow(10, len - j);
		}
	}

	vector<pair<char, int>> sorted_map(map.begin(), map.end());

	sort(sorted_map.begin(), sorted_map.end(),
		[](const pair<char, int>& a, const pair<char, int>& b) -> bool
	{
		return a.second > b.second;
	});

	int num = 9, ret = 0;
	for (const pair<char, int> now : sorted_map)
	{
		ret += now.second * num--;
	}

	cout << ret << "\n";

	return 0;
}