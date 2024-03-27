#include<iostream>
#include<algorithm>

#define MAX_NUM 1000004
#define INF 1e18 + 4

using namespace std;

typedef long long ll;

struct Room
{
	ll t,
		a,
		h;
};
int n;
ll MaxHP, atk;
Room room[MAX_NUM];

bool check(ll CurrentHP)
{
	ll mx = CurrentHP;
	ll atk_now = atk;

	for (int i = 0; i < n; i++)
	{
		if (room[i].t == 1)
		{
			ll damage = room[i].a * (room[i].h / atk_now + (room[i].h % atk_now ? 1 : 0) - 1);
			CurrentHP -= damage;
		}
		else
		{
			atk_now += room[i].a;
			CurrentHP = min(CurrentHP + room[i].h, mx);
		}
		if (CurrentHP <= 0) return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> atk;

	for (int i = 0; i < n; i++)
	{
		cin >> room[i].t >> room[i].a >> room[i].h;
	}

	ll low = 1, high = INF, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (check(mid))
		{
			MaxHP = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	cout << MaxHP << "\n";

	return 0;
}