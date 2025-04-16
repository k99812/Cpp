#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;

int main()
{
	cin >> n;

	while (n--)
	{
		int k;
		cin >> k;

		vector<char> v(k);
		for (int i = 0; i < k; i++)
		{
			cin >> v[i];
		}
	}

	return 0;
}