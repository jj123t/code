/*************************************************************************
	> File Name: p1042.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon May 29 02:39:12 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    char c;
    string s = "";
    while (c != 'E') {
        cin >> c;
        s = s + c;
    }
    int n = s.size();
    using P = pair<int, int>;
    vector<P> ans1, ans2;
    int aw = 0, bw = 0, al = 0, bl = 0;
    for (auto x : s) {
        if (x == 'W') {
            aw++, bw++;
        }
        else if (x == 'L'){
            al++, bl++;
        }
        if ((aw >= 11 || al >= 11) && abs(aw - al) >= 2) {
            ans1.push_back({aw, al});
            aw = 0, al = 0;
        }
        if ((bw >= 21 || bl >= 21) && abs(bw - bl) >= 2) {
            ans2.push_back({bw, bl});
            bw = 0, bl = 0;
        }
    }
    ans1.push_back({aw, al});
    ans2.push_back({bw, bl});
    for (auto [x, y] : ans1) cout << x << ":" << y << "\n";
    cout << "\n";
    for (auto [x, y] : ans2) cout << x << ":" << y << "\n";
    return 0;
}

