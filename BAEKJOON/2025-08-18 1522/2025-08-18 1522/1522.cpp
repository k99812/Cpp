#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

string str;

int main()
{
	cin >> str;

	int window_size = 0, str_size = str.size();
	for (const char& c : str)
	{
		if (c == 'a') window_size++;
	}

	int ret = INT32_MAX;
	int i = 0, j = 0, b_cnt = 0;
	for (i; i < str_size; i++)
	{
		while (j < i + window_size)
		{
			if (str[j % str_size] == 'b') b_cnt++;
			j++;
		}

		ret = min(ret, b_cnt);

		if (str[i] == 'b') b_cnt--;
	}

	cout << ret << "\n";

	return 0;
}