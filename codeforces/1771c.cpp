/*************************************************************************
	> File Name: 1771c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jun 27 23:16:21 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tt; cin >> tt;
    vector<int> prime;
    vector<int> used(101010);
    for (int i = 2; i <= 100100; i++) {
        if (!used[i]) prime.push_back(i);
        for (int j = 2 * i; j <= 100100; j += i) {
            used[j] = true;
        }
    }
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (auto &x : arr) cin >> x;
        map<int, bool> vis;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            int t = arr[i];
            if (flag) break;
            for (auto x : prime) {
                if (x * x > t) break;
                if (t % x == 0) {
                    if (vis[x]) {
                        flag = true;
                    }
                    vis[x] = true;
                    while (t % x == 0) {
                        t /= x;
                    }
                }
            }
            if (t >= 2) {
                if (vis[t]) flag = true;
                vis[t] = true;
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

