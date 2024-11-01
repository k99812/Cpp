#include<iostream>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int n;
string s;

int main()
{
	cin >> n >> s;

	map<char, int> m;
	int cnt = 0, ret = -1;
	int left = 0, right = 0;

	while (right < s.size())
	{
		if (!m[s[right]]) cnt++;
		m[s[right]]++;

		while (cnt > n)
		{
			if (--m[s[left]] == 0) cnt--;
			left++;
		}

		ret = max(ret, right - left + 1);
		right++;
	}

	cout << ret << "\n";

	return 0;
}