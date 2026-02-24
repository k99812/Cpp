#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n;
vector<string> arr;

int main()
{
	cin >> n;

	arr.assign(n, "");

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int ret = n;
	for (int i = 0; i < n; i++)
	{
		bool flag = true;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] == arr[j])
			{
				flag = true;
				break;
			}

			int k = 0, l = 0;
			while (k < arr[i].size() && l < arr[j].size())
			{
				if (arr[i][k++] != arr[j][l++])
				{
					flag = false;
					break;
				}
			}

			if (flag) break;
		}

		if (i < n - 1 && flag) ret--;
	}

	cout << ret << "\n";

	return 0;
}