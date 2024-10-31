#include<iostream>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int n, ret = -1;
string s;

int main()
{
	cin >> n;
	cin >> s;
	
	int first = 0, second = 0, cnt = 0;
	map<char, int> m;

	while (second < s.size())
	{
		if (!m[s[second]]) cnt++;
		m[s[second]]++;

		while (cnt > n)
		{
			if (--m[s[first]] == 0) cnt--;
			first++;
		}

		ret = max(ret, second - first + 1);
		second++;
	}

	cout << ret << "\n";

	return 0;
}