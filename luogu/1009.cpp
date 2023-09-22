/*************************************************************************
	> File Name: 1009.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jun 18 19:40:56 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int n; cin >> n;
    string res = "1";
    string ans = "0";
    auto mul = [&](int x) {
        int flag = 0;
        for (int i = 0; i < res.size(); i++) {
            int t = flag + (res[i] - '0') * x;
            res[i] = (char)('0' + t % 10);
            flag = t / 10;
        }
        while (flag) {
            res = res + (char)('0' + flag % 10);
            flag /= 10;
        }
    };
    auto plus = [&](string tmp) {
        int i = 0;
        int flag = 0;
        while (i < tmp.size() && i < ans.size()) {
            int x = flag + (tmp[i] - '0') + (ans[i] - '0');
            ans[i] = (char)('0' + x % 10);
            flag = x / 10;
            i++;
        }
        while (i < tmp.size()) {
            int x = flag + (tmp[i] - '0');
            ans += (char)('0' + x % 10);
            flag = x / 10;
            i++;
        }
        while (i < ans.size()) {
            int x = flag + (ans[i] - '0');
            ans[i] = (char)('0' + x % 10);
            flag = x / 10;
            i++;
        }
        while (flag) {
            ans += (char)('0' + flag % 10);
            flag /= 10;
        }
    };
    for (int i = 1; i <= n; i++) {
        mul(i);
        plus(res);
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}

