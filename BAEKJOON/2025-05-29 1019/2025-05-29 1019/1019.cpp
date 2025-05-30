#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> ret;

vector<int> go(int n)
{
	vector<int> temp(10);

	int pos = 1;
	while (n / pos > 0)
	{
		int low = n % pos;
		int now = (n / pos) % 10;
		int high = n / (pos * 10);

		for (int i = 0; i < 10; i++)
		{
			if (i < now)
			{
				temp[i] += (high + 1) * pos;
			}
			else if (i == now)
			{
				temp[i] += high * pos + low + 1;
			}
			else
			{
				temp[i] += high * pos;
			}
		}

		temp[0] -= pos;
		pos *= 10;
	}

	return temp;
}

int main()
{
	cin >> n;

	ret = go(n);

	for (const int& i : ret)
	{
		cout << i << " ";
	}

	return 0;
}