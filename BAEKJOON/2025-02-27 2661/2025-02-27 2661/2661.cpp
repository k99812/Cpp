#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int n;

bool isBad(string num)
{
	int len = num.size();
	int half = len / 2;

	for (int i = 1; i <= half; i++)
	{
		string first = num.substr(len - i * 2, i);
		string second = num.substr(len - i, i);

		if (first == second) return true;
	}

	return false;
}

void go(string num)
{
	if (isBad(num))
	{
		return;
	}

	if (num.size() == n)
	{
		cout << num << "\n";
		exit(0);
	}

	go(num + "1");
	go(num + "2");
	go(num + "3");
}

int main()
{
	cin >> n;

	go("");

	return 0;
}