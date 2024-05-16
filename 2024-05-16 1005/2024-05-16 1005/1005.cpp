#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define MAX_NUM 1000 + 4

using namespace std;

int t, n, k, w, x, y, BuildTime[MAX_NUM], inDeg[MAX_NUM], ret[MAX_NUM];


int main()
{
    cin >> t;

    while (t--) 
    {
        fill(&BuildTime[0], &BuildTime[MAX_NUM], 0);
        fill(&inDeg[0], &inDeg[MAX_NUM], 0);
        fill(&ret[0], &ret[MAX_NUM], 0);
        vector<int> grap[MAX_NUM];
        queue<int> q;

        cin >> n >> k;

        for (int i = 1; i <= n; i++)
        {
            cin >> BuildTime[i];
        }

        for (int i = 0; i < k; i++)
        {
            cin >> x >> y;
            grap[x].push_back(y);
            inDeg[y]++;
        }

        cin >> w;

        for (int i = 1; i <= n; i++)
        {
            if (!inDeg[i]) q.push(i);

            ret[i] = BuildTime[i];
        }

        while (q.size())
        {
            int cur = q.front();
            q.pop();

            for (int i : grap[cur])
            {
                ret[i] = max(ret[i], ret[cur] + BuildTime[i]);

                if (--inDeg[i] == 0) q.push(i);
            }
        }

        cout << ret[w] << "\n";
    }

	return 0;
}