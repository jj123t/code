/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed 19 Apr 2023 12:54:57 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
signed main () {
    string s; cin >> s;
    int n = s.size();
    reverse(s.begin(), s.end());
    map<int, int> mp;
    int ans = 0;
    int x = 0;
    int res = 1;
    mp[0] = 1;
    for (int i = 0; i < n; i++) {
        x = (x % 2019 + (s[i] - '0') * res % 2019) % 2019;
        ans += mp[x];
        mp[x]++;
        res = (res * 10) % 2019;
    }
    cout << ans;
    return 0;
}
