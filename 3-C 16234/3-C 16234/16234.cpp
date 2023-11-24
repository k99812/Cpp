#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int n, l, r, map[54][54], visited[54][54],cnt, sum;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<pair<int, int>> v;

void dfs(int y, int x, vector<pair<int, int>> &v) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (visited[ny][nx]) continue;
		int dist = abs(map[y][x] - map[ny][nx]);
		if (l <= dist && dist <= r) {
			visited[ny][nx] = 1; 
			v.push_back({ ny, nx });
			sum += map[ny][nx];
			dfs(ny, nx, v);
		}
	}
}

int main() {
	cin >> n >> l >> r;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	while (true) {
		bool flag = false;
		fill(&visited[0][0], &visited[53][54], 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j]) continue;
				v.clear();
				visited[i][j] = 1;
				v.push_back({ i, j });
				sum = map[i][j];
				dfs(i, j, v);
				if (v.size() == 1) continue;
				for (pair<int, int> b : v) {
					map[b.first][b.second] = sum / v.size();
					flag = true;
				}
			}
		}
		if (!flag) break;
		cnt++;
	}
	cout << cnt << "\n";

	return 0;

}