#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int solution(string s) 
{
    int ret = s.size();

    for (int i = 1; i <= s.size() / 2; i++)
    {
        int cnt = 1;
        string temp = s.substr(0, i), cur = "";


        for (int j = i; j < s.size(); j += i)
        {
            if (temp == s.substr(j, i)) cnt++;
            else
            {
                if (cnt > 1) cur += to_string(cnt);
                cur += temp;
                temp = s.substr(j, i);
                cnt = 1;
            }
        }

        if (cnt > 1) cur += to_string(cnt);
        cur += temp;

        ret = min(ret, (int)cur.size());
    }

    return ret;
}

int main()
{
    string s;
    cin >> s;

    //cout << s.substr(0, 2) << " : " << s.substr(2, 2) << "\n";

    cout << solution(s) << "\n";

	return 0;
}