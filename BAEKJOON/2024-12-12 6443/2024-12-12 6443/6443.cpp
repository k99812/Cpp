#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	while (n--)
	{
		string s;
		cin >> s;

		vector<char> v;
		
		sort(s.begin(), s.end());

		do 
		{
			cout << s << "\n";
		} while (next_permutation(s.begin(), s.end()));
	}

	return 0;
}