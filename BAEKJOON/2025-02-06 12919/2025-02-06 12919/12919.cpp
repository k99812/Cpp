#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

void go(const string& s, string& t)
{
	if (s == t)
	{
		cout << "1\n";
		exit(0);
	}

	if (s.size() > t.size())
	{
		return;
	}

	if (t.back() == 'A')
	{
		string temp = t;
		temp.pop_back();
		go(s, temp);
	}

	if (t.front() == 'B')
	{
		string temp = t;
		reverse(temp.begin(), temp.end());
		temp.pop_back();
		go(s, temp);
	}
}

int main()
{
	string s, t;
	cin >> s >> t;

	go(s, t);

	cout << "0\n";

	return 0;
}