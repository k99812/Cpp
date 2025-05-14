#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int xCnt, oCnt;
string str;
vector<vector<char>> map;

bool isWin(char c)
{
	for (int i = 0; i < 3; i++)
	{
		if (c == map[i][0] && c == map[i][1] && c == map[i][2]) return true;
		if (c == map[0][i] && c == map[1][i] && c == map[2][i]) return true;
	}

	if (c == map[0][0] && c == map[1][1] && c == map[2][2]) return true;
	if (c == map[0][2] && c == map[1][1] && c == map[2][0]) return true;

	return false;
}

bool isValid()
{
	bool xWin = isWin('X');
	bool oWin = isWin('O');

	if (xWin && oWin) return false;

	if (oCnt > xCnt || xCnt > oCnt + 1) return false;

	if (xWin && xCnt != oCnt + 1) return false;

	if (oWin && xCnt != oCnt) return false;

	if (!xWin && !oWin && xCnt + oCnt != 9) return false;

	return true;
}

int main()
{
	while (cin >> str && str != "end")
	{
		xCnt = 0, oCnt = 0;
		map = vector<vector<char>>(3, vector<char>(3));

		for (int i = 0; i < str.size(); i++)
		{
			map[i / 3][i % 3] = str[i];
			if (str[i] == 'X') xCnt++;
			else if (str[i] == 'O') oCnt++;
		}

		cout << (isValid() ? "valid" : "invalid") << "\n";

	}

	return 0;
}