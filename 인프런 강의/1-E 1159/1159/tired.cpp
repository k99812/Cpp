#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int n;
string sinput;
vector<string> input;
vector <char> ret;


int main() {
	vector<char> lret;
	int cnt;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> sinput;
		input.push_back(sinput);
	}

	for (int i = 0; i < input.size(); i++) {
		cnt = 0;
		for (int j = i + 1; j < input.size(); j++) {
			if (input[j].front() == input[i].front()) {
				cnt++;
			}
		}
		if (cnt >= 4) {
			ret.push_back(input[i].front());
		}
	}

	if (ret.empty()) {
		cout << "PREDAJA";
	}
	else {
		sort(ret.begin(), ret.end());
		ret.erase(unique(ret.begin(), ret.end()), ret.end());
		for (auto a : ret) {
			cout << a;
		}
	}

	return 0;
}