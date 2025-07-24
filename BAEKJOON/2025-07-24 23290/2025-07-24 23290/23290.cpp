#include<iostream>
#include<algorithm>
#include<vector>
#include <functional>

using namespace std;

struct Info
{
	int y, x, d;
};

const int n = 4;

int m, s;
vector<vector<int>> board;
vector<Info> fish;
pair<int, int> shark;

class MyClass
{

};

void go(unique_ptr<MyClass, function<void(MyClass*)>>& test)
{

}

int main()
{
	cin >> m >> s;

	board = vector<vector<int>>(n, vector<int>(n));
	fish = vector<Info>(m);

	for (int i = 0; i < m; i++)
	{
		cin >> fish[i].x >> fish[i].y >> fish[i].d;
		fish[i].x--, fish[i].y--, fish[i].d--;
	}

	cin >> shark.second >> shark.first;
	shark.first--, shark.second--;

	MyClass* myClass = new MyClass();
	unique_ptr<MyClass> ptr2(myClass);
	unique_ptr<MyClass, function<void(MyClass*)>> ptr(new MyClass(), [](MyClass* p) { delete p; });

	go(ptr);

	return 0;
}