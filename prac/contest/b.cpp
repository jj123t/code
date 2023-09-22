/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue May  9 03:57:40 2023
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
signed main () {
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<int> a(n * m, 0);
        for (auto &x : a) cin >> x;
        sort(a.begin(), a.end());
        vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> brr(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> crr(n + 1, vector<int>(m + 1, 0));
        crr[1][1] = a[n / 2];
        crr[1][2] = a[0]; crr[2][1] = a.back();
        auto b = a;
        reverse(b.begin(), b.end());
        int idx = 0;
        int cnt = 0;
        arr[1][1] = a[idx++];
        brr[1][1] = b[cnt++];
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        idx--;
        cnt--;
        if (n > m) {
            arr[2][1] = a[idx++]; 
            arr[1][2] = a[idx++];
            brr[2][1] = b[cnt++];
            brr[1][2] = b[cnt++];
        }
        else {
            arr[1][2] = a[idx++];
            arr[2][1] = a[idx++];
            brr[2][1] = b[cnt++];
            brr[1][2] = b[cnt++];
        }
        int res = 0, ans = 0;
        int tmp = 0;
        if (n > m) {
            for (int i = 2; i <= m; i++) {
                res += abs(arr[1][2] - arr[1][1]);
                ans += abs(brr[1][2] - brr[1][1]);
                tmp += abs(crr[1][2] - crr[1][1]);
            }
            res += abs(arr[1][1] - arr[2][1]) * (n * m - m);
            ans += abs(brr[1][1] - brr[2][1]) * (n * m - m);
            tmp += abs(crr[1][1] - crr[2][1]) * (n * m - m);
        }
        else {
            for (int i = 2; i <= n; i++) {
                res += abs(arr[2][1] - arr[1][1]);
                ans += abs(brr[2][1] - brr[1][1]);
                tmp += abs(crr[2][1] - crr[1][1]);
            }
            res += abs(arr[1][1] - arr[1][2]) * (n * m - n);
            ans += abs(brr[1][1] - brr[1][2]) * (n * m - n);
            tmp += abs(crr[1][1] - crr[1][2]) * (n * m - n);
        }
        cout << max({res, ans, tmp}) << '\n';
    }
    return 0;
}
