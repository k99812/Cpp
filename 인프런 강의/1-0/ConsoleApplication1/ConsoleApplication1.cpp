// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int k, n;
vector<int> per;

//순열
void permtation() 
{
    do 
    {

    }
    while (next_permutation(per.begin(), per.end()));
    
}

//조합
void combi(int start, vector<int> v) 
{
    if (v.size() == k) {
        return;
    }

    for (int i = start + 1; i < n; i++) {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}

//조합
void combi2() 
{
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                cout << i << " " << j << " " << k << "\n";
            }
        }
    }
}

//스플릿
vector<string> split(string input, string delimiter) {

    vector<string> ret;
    long long pos = 0;
    string tokne = "";

    while ((pos = input.find(delimiter)) != string::npos)
    {
        tokne = input.substr(0, pos);
        ret.push_back(tokne);
        input.erase(0, pos + delimiter.length());
    }
    ret.push_back(input);

    return ret;
}

//누적합
int a[100004], n, m, pSum[100004], c, b;
vector<int> ret;

void p_Sum() 
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        pSum[i] = pSum[i - 1] + a[i];
    }

    for (int j = 0; j < m; j++) 
    {
        cin >> c >> b;
        
        ret.push_back(pSum[b] - pSum[c - 1]);
    }
}
