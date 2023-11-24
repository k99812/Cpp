#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

const int max_n = 54;
int n, m, map[max_n][max_n], result = 999999;
vector<pair<int, int>> house, chicken;
vector<vector<int>> chickenList;

void combi(int start, vector<int> v) {
	if (v.size() == m) {
		chickenList.push_back(v);
		return;
	}
	for (int i = start + 1; i < chicken.size(); i++) {
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
	return;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) house.push_back({ i, j });
			if (map[i][j] == 2) chicken.push_back({ i, j });
		}
	}
	vector<int> v;
	combi(-1, v);
	for (vector<int> cList : chickenList) {
		int ret = 0;
		for (pair<int, int> home : house) {
			int min_ = 999999;
			for (int ch : cList) {
				int dist = abs(home.first - chicken[ch].first) + abs(home.second - chicken[ch].second);
				min_ = min(min_, dist);
			}
			ret += min_;
		}
		result = min(result, ret);
	}
	cout << result << "\n";
	return 0;
}