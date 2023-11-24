#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M, map[104][104], ret;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
bool visited[104][104];

void dfs(const int& i, const int& j) {

	visited[i][j] = 1;

	for (int q = 0; q < 4; q++) {
		int x, y;

		x = i + dy[q];
		y = j + dx[q];

		if (visited[x][y] == 1) continue;
		if (x < 0 || y < 0 || x > 100 || y > 100) continue;
		if (map[x][y] == 0) continue;

		dfs(x, y);
	}

	return;
}

int main() {
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; i < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) continue;
			if (visited[i][j] == 1) continue;
			//dfs ½ÃÀÛ½Ã 
			ret++; dfs(i, j);
		}
	}

	return 0;
}