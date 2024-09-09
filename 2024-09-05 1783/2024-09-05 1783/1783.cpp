#include<iostream>
#include<algorithm>

using namespace std;

int n, m, ret;

int main()
{
	cin >> n >> m;

	if (n == 1)
	{
		ret = 1;
	}
	else if (n == 2)
	{
		ret = min((m + 1) / 2, 4);
	}
	else if (m < 7)
	{
		ret = min(4, m);
	}
	else
	{
		ret = m - 2;
	}

	cout << ret << "\n";

	return 0;
}