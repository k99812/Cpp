#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

class MyCalendarTwo 
{
    map<int, int> timeline;

public:
    MyCalendarTwo() 
    {
        
    }

    bool book(int start, int end) 
    {
        timeline[start]++;
        timeline[end]--;

        int events = 0;

        for (const auto& [time, cnt] : timeline)
        {
            events += cnt;

            if (events >= 3)
            {
                timeline[start]--;
                timeline[end]++;
                return false;
            }
        }

        return true;
    }
};

int main()
{

	return 0;
}