/*************************************************************************
	> File Name: c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue 02 May 2023 12:38:24 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    vector<string> s(9);
    for (auto &c : s) cin >> c;
    using P = pair<int, int>;
    vector<P> arr;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (s[i][j] == '#') {
                arr.push_back({i, j});
            }
        }
    }
    for (int i = 0; i < )
    return 0;
}
