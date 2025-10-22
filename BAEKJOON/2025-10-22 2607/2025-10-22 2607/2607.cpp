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

	arr = vector<string>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	vector<char> original(26);
	for (char c : arr[0])
	{
		original[c - 'A']++;
	}

	int ret = 0;
	for (int i = 1; i < n; i++)
	{
		vector<char> alpha = original;
		const string& str = arr[i];

		int extra_cnt = 0;
		int common = 0;
		
		for (char c : str)
		{
			if (alpha[c - 'A'])
			{
				alpha[c - 'A']--;
				common++;
			}
			else
			{
				extra_cnt++;
			}
		}

		int missing = arr[0].size() - common;

		if (extra_cnt == 0 && missing == 0) ret++;
		else if (extra_cnt == 1 && missing == 0) ret++;
		else if (extra_cnt == 0 && missing == 1) ret++;
		else if (extra_cnt == 1 && missing == 1) ret++;
	}

	cout << ret << "\n";

	return 0;
}