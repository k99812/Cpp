#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, a, b;

int main()
{
	cin >> n >> a >> b;

	if (n < a + b - 1)
	{
		cout << -1 << "\n";
		return 0;
	}

	vector<int> ret;

	if (a == 1)
	{
		ret.push_back(b);
		
		for (int i = 0; i < n - b; i++)
		{
			ret.push_back(1);
		}

		for (int i = b - 1; i >= 1; i--)
		{
			ret.push_back(i);
		}
	}
	else
	{
		for (int i = 0; i < n - (a + b - 1); i++)
		{
			ret.push_back(1);
		}

		for (int i = 1; i < a; i++)
		{
			ret.push_back(i);
		}

		ret.push_back(max(a, b));

		for (int i = b - 1; i >= 1; i--)
		{
			ret.push_back(i);
		}
	}

	for (const int& i : ret)
	{
		cout << i << " ";
	}
	cout << "\n";

	return 0;
}