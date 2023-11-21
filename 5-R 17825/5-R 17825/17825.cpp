#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int a[14], mal[4], n = 10, v[54];
vector<int> adj[54];

int move(int Mal_idx, int cnt)
{
	if (Mal_idx == 100) return 100;
	if (adj[Mal_idx].size() >= 2)
	{
		Mal_idx = adj[Mal_idx][1];
		cnt--;
	}
	if (cnt)
	{
		queue<int> q;
		q.push(Mal_idx);
		int nx;
		while (q.size())
		{
			int x = q.front(); q.pop();
			nx = adj[x][0];
			if (nx == 100) break;
			q.push(nx);
			cnt--;
			if (cnt == 0) break;
		}
		return nx;
	}
	return Mal_idx;
}

bool isMal(int Next_Mal_idx, int idx)
{
	if (Next_Mal_idx == 100) return false;
	for (int i = 0; i < 4; i++)
	{
		if (i == idx) continue;
		if (mal[i] == Next_Mal_idx) return true;
	}
	return false;
}

int go(int num)
{
	if (num == n) return 0;
	
	int ret = 0;
	for (int i = 0; i < 4; i++)
	{
		int temp = mal[i];
		int next = move(temp, a[num]);
		if (isMal(next, i)) continue;
		mal[i] = next;
		ret = max(ret, go(num + 1) + v[next]);
		mal[i] = temp;
	}
	return ret;
}

void Push(int here, int there)
{
	adj[here].push_back(there);
}

void SetMap()
{
	for (int i = 0; i <= 19; i++) Push(i, i + 1);
	Push(5, 21); Push(21, 22); Push(22, 23); Push(23, 24);
	Push(15, 29); Push(29, 30); Push(30, 31); Push(31, 24);

	Push(10, 27); Push(27, 28); Push(28, 24); Push(24, 25);
	Push(25, 26); Push(26, 20); Push(20, 100);

	v[1] = 2; v[2] = 4;  v[3] = 6; v[4] = 8; v[5] = 10;
	v[6] = 12; v[7] = 14; v[8] = 16; v[9] = 18; v[10] = 20;
	v[11] = 22; v[12] = 24; v[13] = 26; v[14] = 28; v[15] = 30;
	v[16] = 32; v[17] = 34; v[18] = 36; v[19] = 38; v[20] = 40;
	v[21] = 13; v[22] = 16; v[23] = 19;  v[24] = 25;
	v[27] = 22; v[28] = 24; v[25] = 30; v[26] = 35;
	v[29] = 28; v[30] = 27; v[31] = 26;
}

int main()
{
	for (int i = 0; i < n; i++) cin >> a[i];
	SetMap();

	cout << go(0) << "\n";

	return 0;
}