/*************************************************************************
	> File Name: 1846d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul  7 22:28:38 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define db long double
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        db n, d, h; cin >> n >> d >> h;
        vector<db> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        arr.push_back(1e18);
        db s = arr[0];
        db ans = 0;
        db o = atan(h / (d / 2));
        db D;
        for (int i = 1; i <= n; i++) {
            if (arr[i] - s >= h) {
                D = (d + 0) * h / 2.0;
            }
            else {
                db l = d;
                db r = (d - 2.0 * (arr[i] - s) / tan(o));
                D = (l + r) * (arr[i] - s) / 2.0;
            }
            ans += D;
            s = arr[i];
        }
        cout << setprecision(25) << fixed ;
        cout << ans << "\n";
    }
    return 0;
}

