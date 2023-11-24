#include<iostream>
#include<tuple>
#include<queue>
#include<algorithm>

using namespace std;

int n, m, map[104][104], visited[104][104], ny, nx, ret;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
queue<pair<int, int>> q;

void bfs(pair<int, int> start) {

	q.push(start);
	visited[start.first][start.second] = 1;

	while (q.size()) {
		int y, x;
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			ny = y + dy[i]; nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (map[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
}

int main() {

	cin >> n >> m;
	//cout << n << " " << m << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}

	bfs({ 0,0 });
	cout << visited[n - 1][m - 1] << "\n";

	return 0;
}