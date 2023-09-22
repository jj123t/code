/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed May 17 18:05:10 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
const int N = 500010;
#define int long long 
signed main()
{
    string x; cin >> x;
    reverse(x.begin(), x.end());
    int n = x.size();
    vector<int> sfx(n + 1);
    for (int i = n - 1; i > -1; i--) {
        sfx[i] = sfx[i + 1] + (x[i] - '0');
    }
    vector<int> ans(n, 0);
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        tmp += sfx[i];
        ans[i] = tmp % 10;
        tmp /= 10;
    }
    while (tmp) {
        ans.push_back(tmp % 10);
        tmp /= 10;
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans) cout << x ;
    return 0;
}

