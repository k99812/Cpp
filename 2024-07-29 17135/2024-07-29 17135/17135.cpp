#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX_NUM 15
#define NUM 1000

using namespace std;

int a[MAX_NUM][MAX_NUM], map[MAX_NUM][MAX_NUM], n, m, d, answer, archerCol[MAX_NUM];

int dist(const pair<int, int>& a, const pair<int, int>& b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.first == b.first) return a.second % NUM < b.second % NUM;
    else return a.first < b.first;
}

int attack()
{
    int ret = 0;

    int archerRow = n;
    while (archerRow >= 1)
    {
        vector<pair<int, int>> target;
        for (int k = 0; k < m; k++)
        {
            if (!archerCol[k]) continue;

            vector<pair<int, int>> v;

            for (int i = 0; i < archerRow; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (!map[i][j]) continue;
                    if (dist({ i, j }, { archerRow, k }) > d) continue;

                    v.push_back({ dist({i, j}, {archerRow, k}), i * NUM + j });
                }
            }

            if (v.empty()) continue;

            sort(v.begin(), v.end(), cmp);
            target.push_back({ v[0].second / NUM, v[0].second % NUM });
        }

        for (const pair<int, int>& p : target)
        {
            if (map[p.first][p.second])
            {
                map[p.first][p.second] = 0;
                ret++;
            }
        }

        archerRow--;
    }

    return ret;
}

void go(int n, int idx)
{
    if (n == 3)
    {
        copy(&a[0][0], &a[MAX_NUM - 1][MAX_NUM], &map[0][0]);
        answer = max(answer, attack());
        return;
    }

    for (int i = idx; i < m; i++) 
    {
        archerCol[i] = true;
        go(n + 1, i + 1);
        archerCol[i] = false;
    }
}

int main()
{
    cin >> n >> m >> d;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    go(0, 0);

    cout << answer << "\n";

    return 0;
}