/*************************************************************************
	> File Name: 1657d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Sep  6 19:01:29 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n, C; cin >> n >> C;
    vector<int> res(C + 1);
    for (int i = 1; i <= n; i++) {
        int c, d, h; cin >> c >> d >> h;
        res[c] = max(d * h, res[c]);
    }
    for (int i = 1; i <= C; i++) { 
        for (int j = i; j <= C; j += i) {
            res[j] = max(res[j], res[i] * (j / i));
        }
    } 
    for (int i = 1; i <= C; i++) res[i] = max(res[i], res[i - 1]);
    int m; cin >> m;
    for (int i = 1; i <= m; i++) {
        int d, h; cin >> d >> h;
        auto it = upper_bound(res.begin(), res.end(), d * h);
        if (it == res.end()) cout << -1 << '\n';
        else if (*it == d * h) cout << (int)(it - res.begin()) + 1 << '\n';
        else cout << (int)(it - res.begin()) << '\n'; 
    }
    return 0;
}

