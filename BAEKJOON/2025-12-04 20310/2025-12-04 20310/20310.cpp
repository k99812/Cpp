#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main()
{
	string str;
	cin >> str;

	int one = 0, zero = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '1') one++;
		else zero++;
	}

	one /= 2, zero /= 2;

	for (int i = 0; i < str.size(); i++)
	{
		if (one == 0) break;
		if (str[i] == '1')
		{
			str[i] = 'X';
			one--;
		}
	}

	for (int i = str.size(); i >= 0; i--)
	{
		if (zero == 0) break;
		if (str[i] == '0')
		{
			str[i] = 'X';
			zero--;
		}
	}

	for (const char& c : str)
	{
		if (c == 'X') continue;
		cout << c;
	}
	cout << "\n";

	return 0;
}