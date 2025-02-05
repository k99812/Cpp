#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	string s, t;
	cin >> s >> t;

	while (s.size() < t.size())
	{
		if (t.back() == 'A')
		{
			t.pop_back();
		}
		else
		{
			t.pop_back();
			reverse(t.begin(), t.end());
		}
	}

	cout << (s == t ? 1 : 0) << "\n";

	return 0;
}