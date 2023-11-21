#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;
ll x, y, ret = -1;

int main()
{
	cin >> x >> y;

	ll low = 1, hi = 1e9, mid;
	ll avr = (y * 100) / x;

	while (low <= hi)
	{
		mid = (low + hi) / 2;
		if ((y + mid) * 100 / (x + mid) > avr)
		{
			ret = mid;
			hi = mid - 1;
		}
		else low = mid + 1;
	}

	cout << ret << "\n";

	return 0;
}  