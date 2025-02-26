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
		string first = num.substr(len - (i * 2), i);
		string second = num.substr(len - i, i);

		if (first == second)
		{
			return true;
		}
	}

	return false;
}

void go(int idx, string num)
{
	if (isBad(num))
	{
		return;
	}

	if (idx == n)
	{
		cout << num << "\n";
		exit(0);
	}

	go(idx + 1, num + "1");
	go(idx + 1, num + "2");
	go(idx + 1, num + "3");
}

int main()
{
	cin >> n;

	go(0, "");

	return 0; 
}