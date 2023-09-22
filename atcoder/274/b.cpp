/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon 01 May 2023 03:47:43 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for (auto &a : s) cin >> a;
    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
        int res = 0;
        for (int j = 0; j < n; j++) {
            if (s[j][i] == '#') res++;
        }
        ans[i] = res;
    }
    for (auto c : ans) cout << c << " ";
    return 0;
}
