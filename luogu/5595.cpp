/*************************************************************************
	> File Name: 5595.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Aug 14 22:45:40 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s; cin >> s;
    reverse(s.begin(), s.end());
    string a = "", b = "";
    int wina = 0, winb = 0;
    bool flag = true;
    for (auto c : s) {
        if (c == 'Z') {
            if (wina == winb and wina == 0) a += "0", b += "0";
            else flag = false;
        }
        else if (c == 'X') {
            wina++;
            a += "2", b += "1";
        }
        else {
            winb++;
            a += "1", b += "2";
        }
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if (flag) cout << a << "\n" << b << "\n";
    else cout << -1 << "\n";
    return 0;
}

