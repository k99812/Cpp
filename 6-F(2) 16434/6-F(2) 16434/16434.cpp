#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long ll;
ll n, atk, t, a, h, H, mx, damage;

int main()
{
	cin >> n >> atk;

	for (int i = 0; i < n; i++)
	{
		cin >> t >> a >> h;
		if (t == 1)
		{
			damage = a * (ceil((double) h / atk) - 1);
			if (H < damage)
			{
				mx += damage - H;
				H = 0;
			}
			else
			{
				H -= damage;
			}
		}
		else
		{
			atk += a;
			H = min(H + h, mx);
		}
	}

	cout << mx + 1 << "\n";

	return 0;
}