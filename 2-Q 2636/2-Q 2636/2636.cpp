#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>

using namespace std;

const int max_n = 102;
int n, m, map[max_n][max_n], vistied[max_n][max_n], cnt, siz;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<pair<int, int>> chees;

void bfs(int y, int x) {
	cout << "bfs  실행 " << "\n";
	fill(&vistied[0][0], &vistied[max_n - 1][max_n], 0);
	queue<pair<int, int>> q;
	q.push({ y, x });
	vistied[y][x] = 1;

	while (q.size()) {
		int ny, nx, ty, tx;
		tie(ty, tx) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			ny =ty + dy[i]; nx =tx + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (vistied[ny][nx]) continue;
			if (map[ny][nx] == 1) {
				chees.push_back({ ny, nx });
				vistied[ny][nx] = 1;
			}
			else if (map[ny][nx] == 0) {
				q.push({ ny, nx }); vistied[ny][nx] = 1;
			}
		}
	}
	cout << "치즈 사이즈 :  " << chees.size() << "\n";
}

void melting_chees() {
	for (pair<int, int> p : chees) {
		map[p.first][p.second] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

void solve() {
	bfs(0, 0);
	while (chees.size()) {
		melting_chees(); cnt++; siz = chees.size();
		chees.clear();
		bfs(0, 0);
	}
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	cout << cnt << "\n";
	cout << siz << "\n";
	return 0;
}