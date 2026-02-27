#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int k, n;
string target;
vector<string> arr;

int main()
{
	cin >> k >> n >> target;

	arr.assign(n, "");

	int question_row = -1;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i][0] == '?')
		{
			question_row = i;
		}
	}

	string start = "";
	for (int i = 0; i < k; i++)
	{
		start += (char)('A' + i);
	}

	for (int i = 0; i < question_row; i++)
	{
		for (int j = 0; j < k - 1; j++)
		{
			if (arr[i][j] == '-')
			{
				swap(start[j], start[j + 1]);
			}
		}
	}

	for (int i = n - 1; i > question_row; i--)
	{
		for (int j = 0; j < k - 1; j++)
		{
			if (arr[i][j] == '-')
			{
				swap(target[j], target[j + 1]);
			}
		}
	}

	string ret = "";
	for (int i = 0; i < k - 1; i++)
	{
		if (start[i] == target[i])
		{
			ret += "*";
		}
		else if (start[i] == target[i + 1] && start[i + 1] == target[i])
		{
			ret += "-";
			swap(start[i], start[i + 1]);
		}
		else
		{
			ret += "x";
		}
	}

	if (start != target)
	{
		ret = "";
		for (int i = 0; i < k - 1; i++) ret += "x";
	}

	cout << ret << "\n";

	return 0;
}