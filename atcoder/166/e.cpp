/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu 13 Apr 2023 07:38:07 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
signed main () {
    int n; cin >> n;
    vector<int> arr(n, 0);
    for (auto &a : arr) cin >> a;
    map<int, int> mp;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = i - arr[i - 1];
        int y = i + arr[i - 1];
        ans += mp[x];
        mp[y]++;
    }
    cout << ans;
    return 0;
}
