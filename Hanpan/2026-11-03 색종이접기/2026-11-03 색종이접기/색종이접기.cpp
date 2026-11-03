#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

int n, now_x, now_y;
unordered_map<int, vector<pair<int, int>>> un_map;

void h_fold()
{
    for (int x = 0; x < now_x; x++)
    {
        for (int y = now_y - 1; y >= now_y / 2; y--)
        {
            int now_id = y * n + x;
            int next_id = (now_y - 1 - y) * n + x;

            if (un_map[now_id].empty()) continue;

            for (const auto& [ny, nx] : un_map[now_id])
            {
                un_map[next_id].push_back({ ny, nx });
            }

            un_map[now_id].clear();
        }
    }

    now_y /= 2;
}

void v_fold()
{
    for (int y = 0; y < now_y; y++)
    {
        for (int x = now_x - 1; x >= now_x / 2; x--)
        {
            int now_id = y * n + x;
            int next_id = y * n + (now_x - 1 - x);

            if (un_map[now_id].empty()) continue;

            for (const auto& [ny, nx] : un_map[now_id])
            {
                un_map[next_id].push_back({ ny, nx });
            }

            un_map[now_id].clear();
        }
    }

    now_x /= 2;
}

vector<vector<int>> solution(vector<vector<int>> paper, vector<int> fold, vector<vector<int>> cuts) 
{
    n = paper.size();
    now_x = n, now_y = n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int id = i * n + j;
            un_map[id].push_back({ i, j });
        }
    }

    for (int f : fold)
    {
        if (f == 1) h_fold();
        else v_fold();
    }

    for (const vector<int>& c : cuts)
    {
        int id = c[0] * n + c[1];
        if (un_map[id].size())
        {
            for (const auto& [y, x] : un_map[id])
            {
                paper[y][x] = 0;
            }
        }
    }

    return paper;
}

int main()
{
    return 0;
}