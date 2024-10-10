#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string s;
vector<char> ret;

bool check(const string& s) {
	ret.clear();
	for (int i = 0; i < s.length(); i++) {
		if (isalpha(s[i]) || isblank(s[i]) || s[i] == '.') continue;
		if (ret.size()) {
			if (s[i] == ')') {
				if (ret.back() == '(') ret.pop_back();
				else if (ret.back() == '[') return false;
				else ret.push_back(s[i]);
			}
			else if (s[i] == ']') {
				if (ret.back() == '[') ret.pop_back();
				else if (ret.back() == '(') return false;
				else ret.push_back(s[i]);
			}
			else ret.push_back(s[i]);
		}
		else {
			if (s[i] == ')' || s[i] == ']') return false;
			else ret.push_back(s[i]);
		}
	}
	if (!ret.size()) return true;
	else return false;
}

int main() {

	while (getline(cin, s)) {
		if (s == ".") break;
		
		check(s) ? cout << "yes\n" : cout << "no\n";
	}
	return 0;
}