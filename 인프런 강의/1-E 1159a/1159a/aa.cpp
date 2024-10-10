#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int cnt[26], m;
string s;
vector<char> ret;

int main() {
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> s;

		cnt[s.front() - 'a']++;
	}

	for (int j = 0; j < 26; j++) {
		if (cnt[j] >= 5) {
			ret.push_back((char)(j + 'a'));
		}
	}

	if (ret.empty()) {
		cout << "PREDAJA";
	}
	else {
		for_each(ret.begin(), ret.end(), [](char& c) { cout << c; });
	}

	return 0;
}