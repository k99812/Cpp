#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

string s, p;

int main()
{
	cin >> s >> p;

	int ret = 0, first = 0;

	while (first < p.size())
	{
		int size = p.size() - first;
		while (size > 0)
		{
			if (s.find(p.substr(first, size)) != string::npos)
			{
				break;
			}
			size--;
		}
		
		first += size;
		ret++;
	}

	cout << ret << "\n";

	return 0;
}