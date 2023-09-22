/*************************************************************************
	> File Name: 1782d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul  5 17:20:28 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n; 
        vector<int> arr(n);
        for (auto &x : arr) cin >> x;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = (long long)(sqrt(arr[i]));
            if (x * x == arr[i]) {
                ans++;
            }
        }
        ans = max(1ll, ans);
        map<int, int> vis;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int d = arr[j] - arr[i];
                for (int k = 1ll; k * k <= d; k++) {
                    if (d % k != 0) continue;
                    if ((k + d / k) % 2 != 0 || abs(k - d / k) % 2 != 0) continue;
                    int J = (k + d / k) / 2;
                    int I = (d / k - k) / 2;
                    I *= I, J *= J;
                    int x = I - arr[i];
                    if (vis[x]) continue;
                    vis[x] = true;
                    if (x >= 0 && x <= 1e18) {
                        int res = 0;
                        for (int t = 0; t < n; t++) {
                            int r = (long long)sqrt(arr[t] + x);
                            if (r * r == arr[t] + x) {
                                res++;
                            }
                        }
                        ans = max(ans, res);
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

