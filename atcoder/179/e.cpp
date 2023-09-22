/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon 17 Apr 2023 08:29:00 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 

signed main () {
    int n, x, m; cin >> n >> x >> m;
    map<int, int> mp;
    vector<int> arr;
    int pos = 1;
    while (true) {
        if (mp[x]) {
            int tpos = pos;
            int y = x;
            while (tpos++ <= m + mp[x]) {
                arr.push_back(y);
                y = y * y % m;
            }
            break;
        }
        mp[x] = pos;
        pos++;
        arr.push_back(x);
        x = x * x % m;
    }
    mp[x]--;
    pos--;
    int ans = 0;
    if (n <= m) {
        for (int i = 0; i < n; i++) ans += arr[i];
        cout << ans;
        return 0;
    }
    for (int i = 0; i < mp[x]; i++) {
        ans += arr[i];
    }
    int res = 0;
    for (int i = mp[x]; i < pos; i++) {
        res += arr[i];
    }
    res = res * ((n - mp[x]) / (pos - mp[x]));
    ans += res;
    int r = (n - mp[x]) % (pos - mp[x]);
    for (int i = mp[x]; i < mp[x] + r; i++) {
        ans = (ans + arr[i]);
    }
    cout << ans;
    return 0;
}
