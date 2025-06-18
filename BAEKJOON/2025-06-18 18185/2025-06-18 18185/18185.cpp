#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	v = vector<int>(n + 2);

	for (int i = 0; i < n; i++) cin >> v[i];

	int cost = 0;

	for (int i = 0; i < n; i++)
	{
		int cnt;
		if (v[i + 1] > v[i + 2])
		{
			cnt = min(v[i], v[i + 1] - v[i + 2]);
			v[i] -= cnt;
			v[i + 1] -= cnt;
			cost += 5 * cnt;
		}

		cnt = min({ v[i], v[i + 1], v[i + 2] });
		v[i] -= cnt;
		v[i + 1] -= cnt;
		v[i + 2] -= cnt;
		cost += 7 * cnt;

		cnt = min(v[i], v[i + 1]);
		v[i] -= cnt;
		v[i + 1] -= cnt;
		cost += 5 * cnt;

		cost += 3 * v[i];
		v[i] = 0;
	}

	cout << cost << "\n";

	return 0;
}