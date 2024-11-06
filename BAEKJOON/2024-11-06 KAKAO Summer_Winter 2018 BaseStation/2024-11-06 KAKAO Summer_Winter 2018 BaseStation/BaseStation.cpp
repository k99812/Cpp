#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int ret = 0, prev = 0, size = w * 2 + 1;

    for (int here : stations)
    {
        int a = (here - w - 1) - prev;

        ret += (int)ceil((double)a / (double)(w * 2 + 1));

        prev = here + w;
    }

    ret += (int)ceil((double)(n - prev) / (double)(w * 2 + 1));

    return ret;
}

int go(int n, vector<int> stations, int w)
{
    int ret = 0, size = w * 2 + 1;
    vector<int> check(n + 1);

    for (int here : stations)
    {
        int min_num = max(0, here - w);
        int max_num = min(n, here + w);

        for (int i = min_num; i <= max_num; i++)
        {
            check[i] = true;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!check[i])
        {
            cnt++;
        }
        else
        {
            if (cnt)
            {
                ret += cnt / size;
                ret += (cnt % size) ? 1 : 0;
                cnt = 0;
            }
        }
    }

    if (cnt)
    {
        ret += cnt / size;
        ret += (cnt % size) ? 1 : 0;
    }

    return ret;
}

int main()
{
    int n, w;
    vector<int> stations;

    n = 16, w = 2;
    stations.push_back(9);
    //stations.push_back(11);

    cout << solution(n, stations, w);
}