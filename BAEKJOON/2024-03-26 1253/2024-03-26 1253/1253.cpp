#include<iostream>
#include<algorithm>

#define MAX_NUM 2004

using namespace std;

int n, a[MAX_NUM], ret;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n);

	for (int i = 0; i < n; i++)
	{
		int left = 0, right = n - 1;

		while (left < right)
		{
			int sum = a[left] + a[right];

			if (sum == a[i])
			{
				if (left != i && right != i)
				{
					ret++;
					break;
				}
				else if (left == i)
				{
					left++;
				}
				else if (right == i)
				{
					right--;
				}
				
			}
			else if (sum > a[i])
			{
				right--;
			}
			else
			{
				left++;
			}
		}
	}

	cout << ret << "\n";

	return 0;
}