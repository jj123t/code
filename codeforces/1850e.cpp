/*************************************************************************
	> File Name: 1850e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 21 23:01:52 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> arr(n + 1);
        int s = 0;
        int sa = 0;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            s += arr[i] * arr[i];
            sa += arr[i];
        }
        int w = (k - s) / 4;
        int b = sa;
        int a = n;
        int x = (- b / a / 2 + (long long)(sqrt(b / 2 * b / 2 / a / a + w / a)));
        cout << x << "\n";
    }
    return 0;
}

