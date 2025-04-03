#include<iostream>
#include<algorithm>
#include<vector>

#define MOD 1000

using namespace std;

typedef long long ll;

int n;
ll b;
vector<vector<int>> matrix;

vector<vector<int>> multiply(const vector<vector<int>>& a, const vector<vector<int>>& b)
{
	vector<vector<int>> ret(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				ret[i][j] += a[i][k] * b[k][j];
			}

			ret[i][j] %= MOD;
		}
	}

	return ret;
}

vector<vector<int>> power(ll num)
{
	vector<vector<int>> ret(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		ret[i][i] = 1;
	}

	while (num)
	{
		if (num % 2)
		{
			ret = multiply(ret, matrix);
		}

		matrix = multiply(matrix, matrix);
		num /= 2;
	}

	return ret;
}

int main()
{
	cin >> n >> b;

	matrix = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}

	vector<vector<int>> ret = power(b);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << ret[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}