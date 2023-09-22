/*************************************************************************
	> File Name: 1303.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jun 17 05:13:29 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    string a, b; cin >> a >> b;
    reverse(b.begin(), b.end());
    string ans = "0";
    auto plus = [&](string tmp) {
        int i = 0;
        string res = "";
        reverse(ans.begin(), ans.end());
        reverse(tmp.begin(), tmp.end());
        int flag = 0;
        while (i < tmp.size() && i < ans.size()) {
            int x = (ans[i] - '0' + tmp[i] - '0' + flag); 
            res += (char)(x % 10 + '0');
            flag = x / 10;
            i++;
        }
        while (i < ans.size()) {
            int x = (ans[i] - '0' + flag) ;
            res += (char)(x % 10 + '0');
            flag = x / 10;
            i++;
        } 
        while (i < tmp.size()) {
            int x = (tmp[i] - '0' + flag) ;
            res += (char)(x % 10 + '0');
            flag = x / 10;
            i++;
        }
        while (flag) {
            res += (char)(flag % 10 + '0');
            flag /= 10;
        }
        reverse(res.begin(), res.end());
        ans = res;

    };
    string res = "";
    for (int i = 0; i < b.size(); i++, res += "0") {
        string tmp = a;
        int x = b[i] - '0';
        reverse(tmp.begin(), tmp.end());
        int flag = 0;
        for (int i = 0; i < tmp.size(); i++) {
            int t = (tmp[i] - '0') * x + flag;
            tmp[i] = (char)(t % 10 + '0');
            flag = t / 10;
        }
        while (flag) {
            tmp += (char)(flag % 10 + '0');
            flag /= 10;
        }
        reverse(tmp.begin(), tmp.end());
        plus(tmp + res);
    }
    bool up = false;
    for (int i = 0; i < ans.size(); i++) {
        if (!up && ans[i] == '0') {
            continue;
        }
        else {
            up = true;
            cout << ans[i];
        }
    }
    if (!up) {
        cout << 0;
    }
    return 0;
}

