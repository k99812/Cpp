#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

string str;

int main()
{
	cin >> str;

	vector<char> alpha;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'P')
		{
			alpha.push_back(str[i]);
			continue;
		}

		if (alpha.size() < 2 || i + 1 >= str.length() ||str[i + 1] != 'P')
		{
			cout << "NP" << "\n";
			return 0;
		}

		alpha.pop_back();
		i++;
	}

	if (alpha.size() == 1 && alpha[0] == 'P')
	{
		cout << "PPAP" << "\n";
	}
	else
	{
		cout << "NP" << "\n";
	}

	return 0;
}