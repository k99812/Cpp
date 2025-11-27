#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

struct Info
{
	ll a, b, c;
};

const ll MAX = 2147483647;
int n;
vector<Info> arr;

ll getSum(const ll& num)
{
	ll sum = 0;
	for (const Info& info : arr)
	{
		if (info.a > num) continue;

		ll end = min(num, info.c);

		sum += (end - info.a) / info.b + 1;
	}

	return sum;
}

int main()
{
	cin >> n;

	arr = vector<Info>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].a >> arr[i].c >> arr[i].b;
	}

	ll left = 1, right = MAX, ret = -1;
	while (left <= right)
	{
		ll mid = (left + right) / 2;

		if (getSum(mid) %2 != 0)
		{
			ret = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	if (ret == -1) cout << "NOTHING" << "\n";
	else cout << ret << " " << getSum(ret) - getSum(ret - 1) << "\n";
	
	return 0;
}