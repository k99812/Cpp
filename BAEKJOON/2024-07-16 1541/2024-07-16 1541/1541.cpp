#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

void split(const string& s, vector<int>& num, vector<char>& oper)
{
	string temp = "";
	for (char c : s)
	{
		if (c == '+' || c == '-')
		{
			num.push_back(stoi(temp));
			temp = "";
			oper.push_back(c);
			continue;
		}
		temp += c;
	}

	if (temp.length())
	{
		num.push_back(stoi(temp));
		temp = "";
	}
}

int main()
{
	string s = "";
	vector<int> num;
	vector<char> oper;

	cin >> s;

	split(s, num, oper);

	int ret = num[0];
	bool flag = false;

	for (int i = 0; i < oper.size(); i++)
	{
		if (oper[i] == '-') flag = true;
		if (flag)
		{
			ret -= num[i + 1];
		}
		else
		{
			ret += num[i + 1];
		}
	}

	cout << ret << "\n";

	return 0;
}