/*************************************************************************
	> File Name: 1851b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul 25 22:20:09 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        using P = pair<int, int>;
        vector<int> arr(n + 1);
        vector<int> brr, crr;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            arr[i] = x;
            if (x & 1) brr.push_back(x);
            else crr.push_back(x);
        }
        sort(brr.begin(), brr.end());
        sort(crr.begin(), crr.end());
        int a = 0, b = 0;
        for (int i = 1; i <= n; i++) {
            if (arr[i] & 1) arr[i] = brr[a++];
            else arr[i] = crr[b++];
        }
        auto cp = arr;
        sort(cp.begin() + 1, cp.end());
        if (cp == arr) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

