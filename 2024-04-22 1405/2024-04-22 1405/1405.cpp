#include<iostream>
#include<algorithm>

using namespace std;

const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };
double n, percentage[4];
int visited[30][30];

double dfs(int y, int x, int cnt)
{
	if (cnt == n)
	{
		return 1.0;
	}

	double ret = 0.0;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];

		if (visited[ny][nx]) continue;

		visited[ny][nx] = true;
		ret += percentage[i] * dfs(ny, nx, cnt + 1);
		visited[ny][nx] = false;
	}

	return ret;
}

int main()
{
	cin >> n;

	for (int i = 0; i < 4; i++)
	{
		cin >> percentage[i];
		percentage[i] /= 100.0;
	}

	visited[15][15] = 1;
	cout.precision(10);
	cout<< fixed << dfs(15, 15, 0) << "\n";

	return 0;
}