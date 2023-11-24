#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int Max_N = 51, Max_M = 51;
int t, n, m, k, x, y, map[Max_M][Max_N], ret;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1 , 0, -1 };
bool visited[Max_M][Max_N];

void dfs(int y, int x) {
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {

		int ny = y + dy[i], nx = x + dx[i];

		if (ny < 0 || nx <0 || ny >= n || nx >= m) continue;
		if (map[ny][nx] == 0) continue;
		if (visited[ny][nx]) continue;
		dfs( ny, nx);
	}
	return;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	for (int i = 0; i < t; i++) {

		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		ret = 0;

		cin >> m >> n >> k;

		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			map[y][x] = 1;
		}

		for (int k = 0; k < n; k++) {
			for (int j = 0; j < m; j++) {
				if (map[k][j] == 0) continue;
				if (visited[k][j]) continue;
				dfs(k, j); ret++; 
			}
		}
		cout << ret << "\n";
	}

	return 0;
}