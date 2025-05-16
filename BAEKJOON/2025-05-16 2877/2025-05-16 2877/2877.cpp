#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int n;

int main()
{
	cin >> n;

	string ret;

	while (n > 0)
	{
		if (n % 2 == 0)
		{
			ret += "7";
		}
		else
		{
			ret += "4";
		}

		n = (n - 1) / 2;
	}

	reverse(ret.begin(), ret.end());

	cout << ret << "\n";

	return 0;
}