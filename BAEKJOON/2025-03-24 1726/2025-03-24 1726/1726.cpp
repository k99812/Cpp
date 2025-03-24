#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Info
{
	int y,
		x,
		dir;
};

int n, m;
vector<vector<int>> map;
Info start, endpoint;

int main()
{
	cin >> n >> m;

	map.resize(n, vector<int>(m));

	cin >> start.y >> start.x >> start.dir;
	cin >> endpoint.x >> endpoint.y >> endpoint.dir;

	return 0;
}