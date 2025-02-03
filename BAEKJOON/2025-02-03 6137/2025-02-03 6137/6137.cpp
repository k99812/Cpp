#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<char> str(n);
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}

	string ret;
	int left = 0, right = n - 1;
	while (left <= right)
	{
		if (str[left] < str[right])
		{
			ret += str[left++];
		}
		else if (str[left] > str[right])
		{
			ret += str[right--];
		}
		else
		{
			int temp_left = left + 1, temp_right = right - 1;
			bool flag = true;

			while (temp_left <= temp_right && flag)
			{
				if (str[temp_left] < str[temp_right])
				{
					ret += str[left++];
					flag = false;
				}
				else if (str[temp_left] > str[temp_right])
				{
					ret += str[right--];
					flag = false;
				}
				else
				{
					++temp_left, --temp_right;
				}
			}

			if (flag)
			{
				ret += str[left++];
			}
		}
	}

	for (int i = 0; i < ret.size(); i++) 
	{
		if (i != 0 && i % 80 == 0) cout << "\n";
		cout << ret[i];
	}

	return 0;
}