#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAX_SQRT = 45000;

ll k;
vector<int> mu, min_prime, prime;

void mobius()
{
	mu[1] = 1;
	for (int i = 2; i <= MAX_SQRT; i++)
	{
		if (min_prime[i] == 0)
		{
			min_prime[i] = i;
			prime.push_back(i);
			mu[i] = -1;
		}

		for (int p : prime)
		{
			if (p > min_prime[i] || 1LL * i * p > MAX_SQRT) break;

			min_prime[i * p] = p;

			if (i % p == 0) mu[i * p] = 0;
			else mu[i * p] = -mu[i];
		}
	}
}

ll countSquareFree(ll n)
{
	ll cnt = 0;
	for (ll d = 1; d * d <= n; d++)
	{
		cnt += 1LL * mu[d] * (n / (d * d));
	}
	return cnt;
}

int main()
{
	cin >> k;

	mu = min_prime = vector<int>(MAX_SQRT + 1);

	mobius();

	ll low = 1, high = 2000000000;
	ll ret = high;

	while (low <= high)
	{
		ll mid = (low + high) / 2;

		if (countSquareFree(mid) >= k)
		{
			ret = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	cout << ret << "\n";

	return 0;
}