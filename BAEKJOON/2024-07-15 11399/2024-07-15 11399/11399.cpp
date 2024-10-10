#include<iostream>
#include<algorithm>

#define MAX_NUM 1000 + 4 

using namespace std;

int n, a[MAX_NUM], sum[MAX_NUM], ret;

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	sort(&a[1], &a[n + 1]);

	for (int i = 1; i <= n; i++)
	{
		sum[i] += sum[i - 1] + a[i];
		ret += sum[i];
	}
	
	cout << ret << "\n";

	return 0;
}