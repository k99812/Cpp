#include<iostream>
#include<algorithm>

#define MAX_NUM 1000000 + 4
#define NANO 10000000

using namespace std;

int x, n, a[MAX_NUM];

int main()
{
	while (cin >> x >> n)
	{
		fill(&a[0], &a[MAX_NUM], 0);
		x *= NANO;

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		sort(&a[0], &a[n]);

		int left = 0, right = n - 1;
		bool flag = false;

		while (left < right)
		{
			int sum = a[left] + a[right];

			if (sum == x)
			{
				flag = true;
				break;
			}

			if (sum < x)
			{
				left++;
			}
			else if (sum > x)
			{
				right--;
			}
		}

		flag ? cout << "yes " << a[left] << " " << a[right] << "\n" : cout << "danger\n";
	}

	return 0;
}