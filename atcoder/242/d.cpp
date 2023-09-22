/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jun 30 13:22:32 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int dfs(int t, int k) {
    if (t == 0) return s[k] - 'A';
    if (k == 0) return (s[k] - 'A' + t) % 3;
    return (dfs(t - 1, k / 2) + k % 2 + 1) % 3;
}
signed main()
{
    cin >> s;
    int q; cin >> q;
    while (q--) {
        int t, k; cin >> t >> k;
        cout << char(dfs(t, k - 1) + 'A') << "\n";
    }
    return 0;
}

