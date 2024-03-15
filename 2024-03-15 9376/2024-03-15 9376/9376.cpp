#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<string.h>

#define INF 0xf

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int t, h, w, dist[3][104][104];
char m[104][104];
pair<int, int> sinner[2];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int idx, const pair<int, int>& start)
{
    dist[idx][start.first][start.second] = 0;
    pq.push({ 0, start.first * 1000 + start.second });

    while (pq.size())
    {
        int here_y = pq.top().second / 1000, here_x = pq.top().second % 1000;
        int cost = pq.top().first;
        pq.pop();

        if (dist[idx][here_y][here_x] != cost) continue;

        for (int i = 0; i < 4; ++i)
        {
            int ny = here_y + dy[i], nx = here_x + dx[i];
            int next_cost = cost;

            if (ny < 0 || nx < 0 || ny > h + 1 || nx > w + 1) continue;

            if (m[ny][nx] == '*') continue;
            else if (m[ny][nx] == '#') next_cost++;

            if (dist[idx][ny][nx] > dist[idx][here_y][here_x] + next_cost)
            {
                pq.push({ next_cost, ny * 1000 + nx });
                dist[idx][ny][nx] = next_cost;
            }
        }
    }

}

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> h >> w;
        memset(dist, INF, sizeof(dist));

        int order = 0;
        string s;
        for (int i = 1; i <= h; i++)
        {
            cin >> s;
            s = '.' + s + '.';
            for (int j = 0; j <= w + 1; j++)
            {
                m[i][j] = s[j];
                if (m[i][j] == '$')
                {
                    sinner[order++] = { i,j };
                }
            }
        }

        for (int i = 0; i <= w + 1; i++)
        {
            m[0][i] = '.';
            m[h + 1][i] = '.';
        }

        dijkstra(0, { 0, 0 });
        dijkstra(1, sinner[0]);
        dijkstra(2, sinner[1]);

        int min_open_num = 1e9;
        int opened_doors;
        for (int i = 0; i <= h + 1; i++)
        {
            for (int j = 0; j <= w + 1; j++)
            {
                if (m[i][j] == '*')
                    continue;

                opened_doors = dist[0][i][j] + dist[1][i][j] + dist[2][i][j];
                if (m[i][j] == '#')
                {
                    opened_doors -= 2;
                }
                min_open_num = min(opened_doors, min_open_num);
            }
        }

        cout << min_open_num << '\n';
    }

    return 0;
}