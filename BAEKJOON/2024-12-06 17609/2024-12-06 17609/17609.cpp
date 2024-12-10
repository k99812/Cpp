#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int T;

int check(int left, int right, bool flag, const string& s)
{
	while (left < right)
	{
		if (s[left] != s[right])
		{
			if (flag)
			{
				if (!check(left + 1, right, false, s) || !check(left, right - 1, false, s))
				{
					return 1;
				}
			}
			return 2;
		}
		left++, right--;
	}

	return 0;
}

int main()
{
	cin >> T;

	while (T--)
	{
		string s;
		cin >> s;

		cout << check(0, s.size() - 1, true, s) << "\n";
	}

	return 0;
}