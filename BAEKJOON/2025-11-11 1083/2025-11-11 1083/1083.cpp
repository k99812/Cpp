#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, s;
vector<int> arr;

int main()
{
	cin >> n;

	arr = vector<int>(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cin >> s;

	for (int i = 0; i < n - 1; i++)
	{
		int max_num = arr[i], idx = i;

		for (int j = i + 1; j <= i + s && j < n; j++)
		{
			if (max_num < arr[j])
			{
				max_num = arr[j];
				idx = j;
			}
		}

		for (int j = idx; j > i; j--)
		{
			swap(arr[j], arr[j - 1]);
		}

		s -= (idx - i);

		if (s <= 0) break;
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";

	return 0;
}