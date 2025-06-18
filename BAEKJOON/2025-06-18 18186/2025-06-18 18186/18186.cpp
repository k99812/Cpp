#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int n, B, C;
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> B >> C;
	v = vector<int>(n + 2);

	for (int i = 0; i < n; i++) cin >> v[i];

	ll cost = 0, cnt;

	if (B < C) 
	{ 
		for (int i = 0; i < n; i++)
		{
			cost += v[i];
		}
		cout << cost * B << "\n";
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		if (v[i + 1] > v[i + 2])
		{
			cnt = min(v[i], v[i + 1] - v[i + 2]);
			v[i] -= cnt;
			v[i + 1] -= cnt;
			cost += 1LL * (B + C) * cnt;
		}

		cnt = min({ v[i], v[i + 1], v[i + 2] });
		v[i] -= cnt;
		v[i + 1] -= cnt;
		v[i + 2] -= cnt;
		cost += 1LL * (B + 2 * C) * cnt;

		cnt = min(v[i], v[i + 1]);
		v[i] -= cnt;
		v[i + 1] -= cnt;
		cost += 1LL * (B + C) * cnt;

		cost += 1LL * B * v[i];
		v[i] = 0;
	}

	cout << cost << "\n";

	return 0;
}