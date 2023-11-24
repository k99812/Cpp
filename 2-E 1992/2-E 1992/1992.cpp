#include<iostream>
#include<algorithm>
#include<string>
#include<vector>


using namespace std;

const int max_N = 65;
int n, map[max_N][max_N];
string s;

string quard(int y, int x, int size) {
	if (size == 1) return string(1, map[y][x]);
	char c = map[y][x];
	string ret = "";

	for (int i = y; i < y + size; i++) {
		for (int j = x; j <x + size; j++) {
			if (c != map[i][j]) {
				ret += "(";
				ret += quard(y, x, size / 2);
				ret += quard(y, x + size / 2, size / 2);
				ret += quard(y + size / 2, x, size / 2);
				ret += quard(y + size / 2, x + size / 2, size / 2);
				ret += ")";
				return ret;
			}
		}
	}

	return string(1, map[y][x]);
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			map[i][j] = s[j];
		}
	}

	cout << quard(0, 0, n) << "\n";

	return 0;
}