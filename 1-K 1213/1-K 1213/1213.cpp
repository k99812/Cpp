#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

string in, ret;
char mid;
int cnt[26], flag = 0;

int main() {

	cin >> in;
	
	for (auto a : in) cnt[a - 'A']++;

	for (int i = 'Z'; i >= 'A'; i--) {
		if ((cnt[i - 'A'] % 2) != 0) {

			mid = char(i);  
			flag++;
			cnt[i - 'A']--;
		}

		if (flag == 2) break;

		for (int j = 0; j < cnt[i - 'A']; j += 2) {
			ret = char(i) + ret;
			ret += char(i);
		}
	}
	
	if (flag == 2) { cout << "I'm Sorry Hansoo"; return 0; }
	if(mid) ret.insert(ret.begin() + ret.size() / 2, mid);
	cout << ret;

	return 0;
}