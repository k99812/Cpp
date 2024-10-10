#include<iostream>
#include<algorithm>

using namespace std;

int t, n, m;

int main()
{
	cin >> t;

	while (t--)
	{
		cin >> n >> m;
		
		int ret = 1, temp = 1;

		for (int i = m; i > m - n; i--)
		{
			ret *= i;
			ret /= temp;
			temp++;
		}

		cout << ret << "\n";
	}

	return 0;
}