#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

int n;
vector<string> arr;
unordered_map<char, bool> hash_table;

int main()
{
	cin >> n;
	arr.assign(n, "");

	string dummy;
	getline(cin, dummy);

	for (int i = 0; i < n; i++)
	{
		getline(cin, arr[i]);
	}

	for (int i = 0; i < n; i++)
	{
		int shortcut_idx = -1;
		for (int j = 0; j < arr[i].size(); j++)
		{
			if (j == 0 || arr[i][j - 1] == ' ')
			{
				char now = tolower(arr[i][j]);
				if (hash_table.find(now) == hash_table.end())
				{
					hash_table[now] = true;
					shortcut_idx = j;
					break;
				}
			}
		}

		if (shortcut_idx == -1)
		{
			for (int j = 0; j < arr[i].size(); j++)
			{
				if (arr[i][j] == ' ') continue;

				char now = tolower(arr[i][j]);
				if (hash_table.find(now) == hash_table.end())
				{
					hash_table[now] = true;
					shortcut_idx = j;
					break;
				}
			}
		}

		for (int j = 0; j < arr[i].size(); j++)
		{
			if (j == shortcut_idx)
			{
				cout << '[' << arr[i][j] << ']';
			}
			else
			{
				cout << arr[i][j];
			}
		}
		cout << "\n";
	}

	return 0;
}