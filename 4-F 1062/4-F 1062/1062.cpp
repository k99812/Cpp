#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n, k, words[51];
string s;

//antic           a b c d e f g h i j k l m n o p q r s t u v w x y z

int count(int bit)
{
	int cnt = 0;
	for (int word : words)
	{
		if (word && word == (bit & word)) cnt++;
	}
	return cnt;
}

int go(int index, int k, int bit)
{
	if (k < 0) return 0;
	if (index == 26)
	{
		return count(bit);
	}
	int ret = go(index + 1, k - 1, bit | (1 << index));
	if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a') 
	{
		ret = max(ret, go(index + 1, k, bit));
	}
	return ret;
}

int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (char str : s)
		{
			words[i] |= (1 << (int)(str - 'a'));
		}
	}

	cout << go(0, k, 0) << "\n";
	return 0;
}