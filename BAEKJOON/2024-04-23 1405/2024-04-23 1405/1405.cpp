#include<iostream>
#include<algorithm>

using namespace std;

const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };
int n, vistied[30][30];
double per[4];

double dfs(int idx, int y, int x)
{
	if (idx == n)
	{
		return 1.00;
	}

	double ret = 0.0;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny > 30 || nx > 30) continue;
		if (vistied[ny][nx]) continue;

		vistied[ny][nx] = true;
		ret += per[i] * dfs(idx + 1, ny, nx);
		vistied[ny][nx] = false;
	}

	return ret;
}

int main()
{
	cin >> n;

	for (int i = 0; i < 4; i++)
	{
		cin >> per[i];

		per[i] /= 100.0;
	}

	vistied[15][15] = true;
	cout.precision(10);
	cout << fixed << dfs(0, 15, 15) << "\n";

	return 0;
}