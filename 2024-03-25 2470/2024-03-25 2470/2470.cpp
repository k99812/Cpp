#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

#define INF 2e9

using namespace std;

int n, ret[2], a[100004], minest = INF;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n);

	int left = 0, right = n - 1;
	while (left < right)
	{
		int sum = a[left] + a[right];
		int temp = abs(sum);

		if (minest > temp)
		{
			minest = temp;
			ret[0] = a[left], ret[1] = a[right];

			if (sum == 0)
			{
				break;
			}
		}

		if (sum < 0)
		{
			left++;
		}
		else
		{
			right--;
		}
	}

	cout << ret[0] << " " << ret[1] << "\n";

	return 0;
}