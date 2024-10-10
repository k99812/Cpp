#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
#include <iostream>

//A B C D E F G H I J K L N M O P Q R S T U V W X Y Z

using namespace std;

string str;
int ret[26];
int compare = 0;

int main() {
	fill(&ret[0], &ret[26], 0);

	cin >> str;
	for (auto a : str) {
		compare = 0;
		//cout << (int)a << "\n";
		ret[a % 'a'] += 1;
	}

	for (auto i : ret) {
		cout << i << " ";
	}

	return 0;
}