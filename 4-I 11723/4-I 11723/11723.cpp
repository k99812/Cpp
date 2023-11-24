#include<iostream>
#include<string>

using namespace std;

int m, x, ret;
char s[12];

int main()
{
	scanf_s(" %d", &m);

	for (int i = 0; i < m; i++)
	{
		scanf_s(" %s %d", &s, &x);
		if (s[0] == 'a' && s[1] == 'd') ret |= (1 << x);
		else if (s[0] == 'r') ret &= ~(1 << x);
		else if (s[0] == 'c') printf("%d\n", (ret & (1 << x)) == 0 ? 0 : 1);
		else if (s[0] == 't') ret ^= (1 << x);
		else if (s[0] == 'a' && s[1] == 'l') ret = (1 << 21) - 1;
		else ret = 0;
	}

	return 0;
}