#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll ;

struct Room
{
	ll t,
		a,
		h;
};
int n;
ll CurrentHP, MaxHP, atk, damage;
Room room;

int main()
{
	cin >> n >> atk;

	for (int i = 0; i < n; i++)
	{
		cin >> room.t >> room.a >> room.h;

		damage = room.h / atk + (room.h % atk ? 1 : 0) - 1;

		if (room.t == 1)
		{
			if (CurrentHP < damage)
			{
				MaxHP += damage - CurrentHP;
				CurrentHP = 0;
			}
			else
			{
				CurrentHP -= damage;
			}
		}
		else
		{
			atk += room.a;
			CurrentHP = min(CurrentHP + room.h, MaxHP);
		}
	}

	cout << MaxHP + 1 << "\n";

	return 0;
}