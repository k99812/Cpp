#include <iostream>

using namespace std;

const int n = 10;
bool visit[n], in[n][n];

void go(int i) {
    if (visit[i]) {
        return;
    }

    visit[i] = 1;
    cout << i << "\n";

    for (int j = 0; j < n; j++) {
        if (visit[j]) continue;
        if (in[i][j]) {
            go(j);
        }
    }
}

int main()
{
    in[1][2] = 1, in[2][1] = 1;
    in[1][3] = 1, in[3][1] = 1;
    in[3][4] = 1, in[4][3] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (in[i][j] && visit[i] == 0) {
                go(i);
            }
        }
    }

    return 0;
}