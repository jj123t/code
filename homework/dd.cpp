/*************************************************************************
	> File Name: bb.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed May 17 00:51:31 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    while (true) {
        int n; cin >> n;
        if (n == 0) break;
        int hour; cin >> hour;
        vector<int> fi(n), di(n), ti(n - 1);
        for (auto &x : fi) cin >> x;
        for (auto &x : di) cin >> x;
        for (auto &x : ti) cin >> x;

        int ans = 0;
        vector<int> pre(n);
        for (int k = 0, walk = 0; k < n; k++, walk += ti[k - 1] * 5) {
            int minute = hour * 60 - walk; 
            int now = 0, res = 0;
            vector<int> f(n); f = fi;
            vector<int> dohour(n, 0);
            while (minute - 5 >= 0) {
                int tmpcan = 0;
                int idx = now;
                for (int i = 0; i <= k; i++) {
                    if (f[i] > tmpcan) {
                        tmpcan = f[i];
                        idx = i;
                    }
                }
                if (f[idx] == 0) break;
                minute -= 5;
                res += f[idx];
                dohour[idx] += 5;
                f[idx] = max(f[idx] - di[idx], 0);
                now = idx;
            }
            if (res > ans) {
                ans = res;
                dohour[0] += minute;
                pre = dohour;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << pre[i];
            if (i == n - 1) cout << '\n';
            else cout << ", ";
        }
        cout << "Number of fish expected: " << ans << '\n';
        cout << '\n';
    }
    return 0;
}
