#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

vector<char> ret;
string s;
int n;
bool is_vps;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		ret.clear(); is_vps = false;

		for (int j = 0; j < s.length(); j++) {
			if (ret.size()) {
				if (s[j] == ')') {
					if (ret.back() == '(') ret.pop_back();
					else { ret.push_back(s[j]); is_vps = false; break; }
				}
				else ret.push_back(s[j]);
			}
			else {
				if (s[j] == ')') { ret.push_back(s[j]);  is_vps = false; break; }
				else ret.push_back(s[j]);
			}
		}
		cout << ret.size() << " ret.size \n";
		if (!ret.size()) is_vps = true;
		is_vps ? cout << "YES\n" : cout << "NO\n";
	}

	return 0;
}