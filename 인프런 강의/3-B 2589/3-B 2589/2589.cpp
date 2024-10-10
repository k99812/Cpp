#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>

using namespace std;

int n, m, map[54][54], visited[54][54], ret = -1;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;
string s;

void bfs(int y, int x) {
	fill(&visited[0][0], &visited[53][54], 0);
	visited[y][x] = 1;
	q.push({ y, x });
	while (q.size()) {
		int ty, tx, ny, nx;
		tie(ty, tx) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			ny = ty + dy[i]; nx = tx + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (map[ny][nx]) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] =visited[ty][tx] + 1; q.push({ny, nx});
			ret = max(ret, visited[ny][nx]);
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			s[j] == 'W' ? map[i][j] = 1 : map[i][j] = 0;
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j]) continue;
			bfs(i, j);
		}
	}

	cout << ret-1 << "\n";

	return 0;
}