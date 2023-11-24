#include<iostream>
#include<algorithm>

using namespace std;

const int Max_N = 101;
int n, map[Max_N][Max_N], ret = 1, h, num;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
bool visited[Max_N][Max_N];

void dfs(int y, int x) {

	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (map[ny][nx] <= h) continue;
		if (visited[ny][nx]) continue;
		dfs(ny, nx);
	}
	return;
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for ( h = 1; h <= 100; h++) {
		fill(&visited[0][0], &visited[Max_N - 1][Max_N], 0);
		num = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if( map[i][j] <= h) continue;
				if (visited[i][j]) continue;
				dfs(i, j);  num++;
			}
		}
		ret = max(ret, num);
	}

	cout << ret << "\n";
	return 0;
}