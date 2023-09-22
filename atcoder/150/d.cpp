/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue 11 Apr 2023 07:46:45 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
int lcm(int a, int b) {
    return a * b / __gcd(a, b);
}
signed main () {
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for (auto &a : arr) cin >> a;
    int tp = 0;
    int x = arr[0];
    while (x % 2 == 0) tp++, x /= 2;
    int LCM = 1;
    for (auto &a : arr) {
        int s = 0;
        int ts = a;
        while (ts % 2 == 0) s++, ts /= 2;
        LCM = lcm(LCM, a / 2);
        if (s != tp || m < LCM) {
            cout << 0 << "\n";
            return 0;
        }
    }
    int ans = 0;
    for (int i = LCM; i <= m; i += 2 * LCM) ans++;
    cout << ans;
    return 0;
}
