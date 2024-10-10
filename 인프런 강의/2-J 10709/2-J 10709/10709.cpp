#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int h, w, ret[102][102];
string map[102][102];

int main() {

	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < w; j++) {
			map[i][j] = s[j];
		}
	}

	fill(&ret[0][0], &ret[101][102], -1);

	for (int i = 0; i < h; i++) {
		int val = -1;
		for (int j = 0; j < w; j++) {
			if (map[i][j] == "c") { ret[i][j] = 0; }
			else {
				if (j > 0) {
					if (ret[i][j - 1] == -1) continue;
					ret[i][j] = ret[i][j - 1] + 1;
				}
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << ret[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}