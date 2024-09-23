#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int num = 4, visited[10], arr[] = { 0, 1, 2, 3, 4};
vector<int> v;

void combi(int idx, int cnt)
{
	if (cnt == 3)
	{
		for (int i = 0; i < num; i++)
		{
			if (visited[i]) cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < num; i++)
	{
		if (visited[i]) continue;
		visited[i] = true;
		combi(i, cnt + 1);
		visited[i] = false;
	}
	return;
}

void combiBit(int idx, int cnt, int v)
{
	if (cnt == 3)
	{
		for (int i = 0; i < num; i++)
		{
			if (v & (1 << i)) cout << i << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < num; i++)
	{
		if (v & (1 << i)) continue;
		
		combiBit(i + 1, cnt + 1, v | (1 << i));
	}
	return;
}

void combiVector(int idx)
{
	if (v.size() == 3)
	{
		for (int i : v)
		{
			cout << i << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = idx; i < num; i++)
	{
		v.push_back(i);
		combiVector(i + 1);
		v.pop_back();
	}

	return;
}

int main()
{
	cout << "º£¿­\n";
	combi(0, 0);

	cout << "bit\n";
	combiBit(0, 0, 0);

	cout << "vector\n";
	combiVector(0);

	return 0;
}