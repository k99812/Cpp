#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string s, bomb, ret;

int main()
{
	cin >> s >> bomb;

	for (char c : s)
	{
		ret += c;
		if (ret.size() >= bomb.size() && ret.substr(ret.size() - bomb.size(), bomb.size()) == bomb)
		{
			ret.erase(ret.end() - bomb.size(), ret.end());
		}
	}
	ret == "" ? cout << "FRULA\n" : cout << ret << "\n";
	return 0;
}