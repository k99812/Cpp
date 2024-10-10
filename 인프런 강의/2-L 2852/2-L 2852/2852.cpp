#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int n, g, acnt, bcnt, asum, bsum;
string t, pre;

string print_nba(int time) {
	string e = "00" + to_string(time / 60);
	string d = "00" + to_string(time%60);
	return e.substr(e.length() - 2, 2) + ":" + d.substr(d.length() - 2, 2);
}

int mtos(string s) {

	return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}

void go(int& sum,string t) {
	sum += mtos(t) - mtos(pre);
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> g >> t;

		if (acnt > bcnt) {
			go(asum, t);
		}
		else if(bcnt > acnt) {
			go(bsum, t);
		}

		g == 1 ? acnt++ : bcnt++;
		pre = t;
	}
	if (acnt > bcnt) {
		go(asum, "48:00");
	}
	else if(bcnt > acnt){
		go(bsum, "48:00");
	}

	cout << print_nba(asum) << "\n";
	cout << print_nba(bsum) << "\n";
	return 0;
}