#include<iostream>
#include<algorithm>

using namespace std;

int D, K;

int fib(int n)
{
	int f[2] = { 0, 1 };
	for (int i = 1; i <= n / 2; i++)
	{
		f[0] += f[1];
		f[1] += f[0];
	}
	return f[n & 1];
}


int main()
{
	cin >> D >> K;

	int x = fib(D), y = fib(D - 1);

	for (int i = 1; i < K / x; i++)
	{
		if ((K - i * x) % y == 0)
		{
			cout << i << "\n";
			cout << (K - i * x) / y + i << "\n";
			break;
		}
	}

	return 0;
}