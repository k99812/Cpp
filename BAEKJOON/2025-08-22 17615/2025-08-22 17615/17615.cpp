#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n;
string str;

int main()
{
	cin >> n >> str;

	int total_r = count(str.begin(), str.end(), 'R');
	int total_b = n - total_r;

	int left_r = 0, left_b = 0, right_r = 0, right_b = 0;

    for (char c : str) 
    {
        if (c == 'R') left_r++;
        else break;
    }

    for (char c : str) 
    {
        if (c == 'B') left_b++;
        else break;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] == 'R') right_r++;
        else break;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] == 'B') right_b++;
        else break;
    }

    int ret = n;

    if (total_r > 0)
    {
        ret = min(ret, total_r - left_r);
        ret = min(ret, total_r - right_r);
    }

    if (total_b > 0)
    {
        ret = min(ret, total_b - left_b);
        ret = min(ret, total_b - right_b);
    }
    
    cout << ret << "\n";

	return 0;
}