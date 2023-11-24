#include<iostream>
#include<algorithm>

using namespace std;

int t, in;
int cnt_2, cnt_5;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> in;
		cnt_2 = 0; cnt_5 = 0;
		
		for (int j = 2; j <= in; j *= 2) {
			cnt_2 += in / j;
		}

		for (int j = 5; j <= in; j *= 5) {
			cnt_5 += in / j;
		}

		cout << min(cnt_2, cnt_5) << "\n";
	}

	return 0;
}