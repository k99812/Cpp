#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int w, s;
string str_w, str_s;

int get_idx(char c)
{
	if ('a' <= c && c <= 'z') return c - 'a';
	else return c - 'A' + 26;
}

int main()
{
	cin >> w >> s >> str_w >> str_s;

	vector<int> countW(52, 0);
	vector<int> countS(52, 0);

	for (const char c : str_w)
	{
		countW[get_idx(c)]++;
	}

	int ret = 0, len = 0, left = 0;

	for (int right = 0; right < s; right++)
	{
		countS[get_idx(str_s[right])]++;
		len++;

		if (len == w)
		{
			if (countW == countS)
			{
				ret++;
			}

			countS[get_idx(str_s[left])]--;
			left++, len--;
		}
	}

	cout << ret << "\n";

	return 0;
}