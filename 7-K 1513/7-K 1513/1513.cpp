#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int dy[] = { 1, 0 };
const int dx[] = { 0, 1 };
int n, m, c, a[54][54];
vector<pair<int, int>> v(54);

int go(int y, int x, int cnt, int prev)
{
	if (y == n && x == m) return 1;
	
	for (int i = 0; i < 2; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];

		if (ny < 1 || nx <1 || ny > n || nx > m) continue;
		go(ny, nx, num);
	}
}

int main()
{
	cin >> n >> m >> c;

	for (int i = 1; i <= c; i++) 
	{ 
		cin >> v[i].first >> v[i].second; 
		a[v[i].first][v[i].second] = i;
	}

	return 0;
}