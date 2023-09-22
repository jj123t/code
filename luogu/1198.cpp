/*************************************************************************
	> File Name: 1198.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int m, d; cin >> m >> d;
    vector<vector<int>> st(m + 1, vector<int>(26, 0));
    auto get = [&](int l, int r) -> int {
        int x = log2(r - l + 1);
        return max(st[l][x], st[r - (1 << x) + 1][x]);
    };
    int t = 0;
    int r = 0;
    for (int j = 0; j < m; j++) {
        char c; int x; cin >> c >> x;
        if (c == 'Q') {
            t = get(r - x + 1, r);
            cout << t << "\n";
        }
        else {
            int res = (t + x) % d;
            st[++r][0] = res;
            for (int i = 1; (1 << i) <= r; i++) {
                st[r - (1 << i) + 1][i] = max(st[r - (1 << i) + 1][i - 1], st[r - (1 << i) + 1 + (1 << (i - 1))][i - 1]);
            }
        }
    }
    return 0;
}

