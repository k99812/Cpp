#include<iostream>
#include<queue>

using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
int map[3][3];
bool visit[3][3];
queue<pair<int, int>> num;

int main() {

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}

	for (int z = 0; z < 3; z++) {
		for (int j = 0; j < 3; j++) {

			if (!visit[z][j] && map[z][j] == 1) {
				num.push(make_pair(z, j));
				visit[z][j] = 1;
			}

			while (!num.size()) {
				pair<int, int> temp = num.front();
				num.pop();
				for (int i = 0; i < 4; i++) {
					int ty = temp.first + dy[i], tx = temp.second + dx[i];
					if (ty >= 0 && tx >= 0 && tx < 3 && ty < 3) {
						if (!visit[ty][tx] && map[ty][tx] == 1) {
							num.push(make_pair(ty, tx));
							visit[ty][tx] = 1;
						}

					}
				}
			}
		}
	}
	

	return 0;
}