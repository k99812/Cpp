#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

string input;
vector<char> ret;

int main() {
	int temp;
	getline(cin, input);
	//cout << input;

	for (auto a : input) {
		temp = 0;
		if (isalpha(a)) {
			if ((int)a < (int)'a') {
				temp = a + 13;
				if (temp >= 'A' + 26) {
					ret.push_back((char)(temp - 26));
				}
				else ret.push_back((char)(temp));
			}
			else {
				temp = a + 13;
				if (temp >= 'a' + 26) {
					ret.push_back((char)(temp - 26));
				}
				else ret.push_back((char)temp);
			}
		}
		else ret.push_back(a);
	}

	for_each(ret.begin(), ret.end(), [](char& c) { cout << c; });

	return 0;
}