#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, x;
vector<int> arr;

int main()
{
	cin >> n >> x;

	arr = vector<int>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int max_num = 0, day = 0, sum = 0, cnt = 0;
	for (int i = 0; i <= n - x; i++)
	{
		while (cnt + i < n && cnt < x)
		{
			sum += arr[i + cnt++];
		}

		if (sum > max_num)
		{
			max_num = sum;
			day = 1;
		}
		else if (sum == max_num)
		{
			day++;
		}

		sum -= arr[i], cnt--;
	}

	if (max_num == 0) cout << "SAD" << "\n";
	else cout << max_num << "\n" << day << "\n";

	return 0;
}