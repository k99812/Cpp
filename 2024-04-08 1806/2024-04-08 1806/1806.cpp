#include<iostream>
#include<algorithm>

#define MAX_NUM 100000 + 4
#define INF 2e9

using namespace std;

typedef long long ll;
int n, a[MAX_NUM];
int s, ret = INF;

int main()
{
	cin >> n >> s;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	int first = 1, second = 1;
	int sum = a[1];
	while (first <= second && second <= n)
	{
		if (sum >= s)
		{
			ret = min(ret, second - first);
		}
		if (sum < s) 
		{
			second++;
			sum += a[second];
		}
		else 
		{
			sum -= a[first];
			first++;
		}
	}

	cout << (ret == INF ? 0 : ret + 1) << "\n";

	return 0;
}