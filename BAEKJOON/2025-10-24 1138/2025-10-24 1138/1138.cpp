#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> arr, ret;

int main()
{
	cin >> n;

	arr = ret = vector<int>(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		int empty = arr[i], cnt = 0;

		for (int j = 1; j <= n; j++)
		{
			if (ret[j]) continue;

			if (cnt == empty)
			{
				ret[j] = i;
				break;
			}

			cnt++;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << ret[i] << " ";
	}
	cout << "\n";

	return 0;
}