#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int INF = 1e9;
int n, maxest = -INF, minest = INF, nums[14];
vector<int> opers(4);


void go(int cnt, int sum, int plus, int minus, int mul, int div)
{
	if (cnt == n - 1)
	{
		maxest = max(maxest, sum);
		minest = min(minest, sum);
		return;
	}

	if (plus) go(cnt + 1, sum + nums[cnt + 1], plus - 1, minus, mul, div);
	if (minus) go(cnt + 1, sum - nums[cnt + 1], plus, minus - 1, mul, div);
	if (mul) go(cnt + 1, sum * nums[cnt + 1], plus, minus, mul - 1, div);
	if (div) go(cnt + 1, sum / nums[cnt + 1], plus, minus, mul, div - 1);
	return;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> opers[i];
	}

	go(0, nums[0], opers[0], opers[1], opers[2], opers[3]);

	cout << maxest << "\n" << minest << "\n";

	return 0;
}