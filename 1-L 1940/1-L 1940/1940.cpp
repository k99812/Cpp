#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, input, ret = 0, s = 2;
vector<int> num, temp;

void combi(const vector<int>& v, int start) {
	if (temp.size() == s) {
		int i = 0;
		for (auto a:temp) {
			i += a;
		}
		if (i == m) ret++; 
		return;
	}
	for (int i = start + 1; i < v.size(); i++) {
		temp.push_back(v[i]);
		combi(v, i);
		temp.pop_back();
	}
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> input;
		num.push_back(input);
	}

	combi(num, -1);
	cout << ret;

	return 0;
}