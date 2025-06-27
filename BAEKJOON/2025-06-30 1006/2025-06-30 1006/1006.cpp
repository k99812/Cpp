#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int T, n, w;
vector<int> enermy, ally;

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> n >> w;

		enermy = vector<int>(n);
		ally = vector<int>(n);

		for (int i = 0; i < n; i++)
		{
			cin >> enermy[i];
		}

		for (int i = 0; i < n; i++)
		{
			cin >> ally[i];
		}
	}

	return 0;
}