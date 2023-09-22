/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue 11 Apr 2023 10:18:02 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
int p;
int mypow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
int inv(int x) {
    return mypow(x, p - 2);
}
signed main () {
    int n; cin >> n >> p;
    string s; cin >> s;
    if (p == 2) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if ((s[i] - '0') % 2 == 0) {
                ans += i + 1;
            }
        }
        cout << ans;
        return 0;
    }
    vector<int> fx(n + 1, 0);
    reverse(s.begin(), s.end());
    for (int i = 0, res = 1; i < n; i++, res *= 10) {
        res %= p;
        fx[i + 1] = (fx[i] + (s[i] - '0') * res) % p;
    }
    map<int, int> mp;
    mp[0] = 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += mp[fx[i + 1]];
        mp[fx[i + 1]]++;
    }
    cout << ans;
    return 0;
}
