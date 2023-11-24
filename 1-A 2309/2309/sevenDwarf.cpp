#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

int n = 9, t;
vector<int> ret, vTemp;

vector<int> make_per(vector<int> &v) {

	int temp = 0;
	vector<int> r;

	do {
		for (int i = 0; i < 7; i++) {
			temp += v[i];
		}
		if (temp == 100) {
			cout << "temp : " << temp << "\n";
			temp = 0;
			return v;
		}
		else {
			temp = 0;
		}

	} while (next_permutation(v.begin(), v.end()));

	return r;
}

int main() 
{
	for (int i = 0; i < n; i++) {
		cin >> t;
		vTemp.push_back(t);

		//for_each(ret.begin(), ret.end(), [](auto& b) {cout << b << " "; });
		//cout << "\n";
	}

	sort(vTemp.begin(), vTemp.end());
	//for_each(vTemp.begin(), vTemp.begin() + 7, [](int& c) { cout << "¼ø¿­ : " << c << " "; });
	cout << "\n";

	ret = make_per(vTemp);
	
	for_each(ret.begin(), ret.begin() + 7, [](int& c) { cout << " " << c << "\n"; });

	return 0;
}