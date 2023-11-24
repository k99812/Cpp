#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n;
string a, b, buffer;
vector<string> temp, val;
bool blank = false;

vector<string> split(string input, string delimiter) {

	vector<string> val;
	long long pos = 0;
	string tokken = "";

	while ((pos = input.find(delimiter)) != string::npos) {
		tokken = input.substr(0, pos);
		val.push_back(tokken);
		input.erase(0, pos + delimiter.length());
	}
	val.push_back(input);

	return val;
}

int main() {

	cin >> n;
	getline(cin, buffer);
	getline(cin, a);

	for (int i = 0; i < n; i++) {
		cin >> b;
		val.push_back(b);
	}

	for (char q : a) {
		if (isblank(q)) {
			blank = true;
		}
	}
	if (blank) temp = split(a, " ");
	else temp = split(a, "*");
	
	cout << "temp : " << temp[0] << " " << temp[1] << "\n";

	for (int i = 0; i < val.size(); i++) {

		string f = "", e = "";

		if (val[i].length() < temp[0].length() + temp[1].length()) {
			cout << "NE" << "\n";
		}
		else {
			f = val[i].substr(0, temp[0].length()); e = val[i].substr(val[i].length() - temp[1].length(), val[i].length());

			if (f == temp[0] && e == temp[1]) {
				cout << "DA" << "\n";
			}
			else cout << "NE" << "\n";
		}
	}

	return 0;
}