#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

const int INF = 1e9;
const int dy[] = { INF, 1, 1, 1, 0, 0, 0, -1, -1, -1 };
const int dx[] = { INF, -1, 0, 1, -1, 0, 1, -1, 0, 1 };

int n, m;
string input;
vector<string> board;
vector<pair<int, int>> crazy;
pair<int, int> pos;

bool go()
{
	for (int idx = 0; idx < input.size(); idx++)
	{
		int dir = input[idx] - '0';
		pos.first += dy[dir], pos.second += dx[dir];

		if (board[pos.first][pos.second] == 'R')
		{
			cout << "kraj " << idx + 1 << "\n";
			return false;
		}

		vector<pair<int, int>> next_crazy;
		vector<vector<int>> arrival_cnt(n, vector<int>(m, 0));

		for (pair<int, int>& arduino : crazy)
		{
			int y = arduino.first, x = arduino.second;

			int ny = y;
			if (pos.first > y) ny++;
			else if (pos.first < y) ny--;

			int nx = x;
			if (pos.second > x) nx++;
			else if (pos.second < x) nx--;

			if (pos.first == ny && pos.second == nx)
			{
				cout << "kraj " << idx + 1 << "\n";
				return false;
			}

			next_crazy.push_back({ ny, nx });
			arrival_cnt[ny][nx]++;
		}

		board.assign(n, string(m, '.'));
		crazy.clear();

		board[pos.first][pos.second] = 'I';

		for (const pair<int, int>& ardu : next_crazy)
		{
			if (arrival_cnt[ardu.first][ardu.second] > 1) continue;
			crazy.push_back(ardu);
			board[ardu.first][ardu.second] = 'R';
		}
	}

	return true;
}

int main()
{
	cin >> n >> m;

	board.assign(n, "");

	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 'R')
			{
				crazy.push_back({ i, j });
			}
			else if (board[i][j] == 'I')
			{
				pos = { i, j };
			}
		}
	}

	cin >> input;

	if (go())
	{
		for (int i = 0; i < n; i++)
		{
			cout << board[i] << "\n";
		}
		cout << "\n";
	}

	return 0;
}