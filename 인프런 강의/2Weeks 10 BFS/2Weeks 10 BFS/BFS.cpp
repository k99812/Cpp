#include<iostream>
#include<queue>
#include<algorithm>
#include<tuple>

using namespace std;

int map[104][104], N, M, ry, rx, cy, cx, visited[104][104], x, y;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;

int main() {

	cin >> N >> M;
	cin >> ry >> rx;
	cin >> cy >> cx;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	visited[ry][rx] = 1;
	q.push(make_pair(ry, rx));

	while (q.size()) {
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx  < 0 || ny >= N || nx >= M) continue;
			if (map[ny][nx] == 0) continue;
			if (visited[ny][nx] > 0) continue;
			//�ִܰŸ� ����
			//visited �迭�� ù ������ 1 �״��� üũ�� visited[y][x] + 1�� �ϸ� �Ÿ� ����
			visited[ny][nx] = visited[y][x] + 1;
			q.push(make_pair(ny, nx));
		}
	}

	cout << visited[cy][cx] << "\n";

	return 0;
}