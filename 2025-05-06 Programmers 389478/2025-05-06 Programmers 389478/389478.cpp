#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int solution(int n, int w, int num)
{
    int ret = 0;

    while (num <= n)
    {
        if (num % w)
        {
            num += (w - (num % w)) * 2 + 1;
        }
        else
        {
            num++;
        }

        ret++;
    }

    return ret;
}

int main()
{
    int n, w, num;

    cin >> n >> w >> num;

    cout << solution(n, w, num) << "\n";

    return 0;
}