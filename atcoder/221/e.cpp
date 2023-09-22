/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri May 12 04:20:05 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define int long long
const int N = 1e6 + 10;
const int p = 998244353;
vector<int> tree(N, 0);
int n;
int mypow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res % p; 
}
int inv(int x) {
    return mypow(x, p - 2) % p;
}
void add(int i, int x) {
    while (i <= n) {
        tree[i] = (tree[i] + x) % p;
        i += i & -i;
    }
}
int qry(int i) {
    int res = 0;
    while (i >= 1) {
        res = (res + tree[i]) % p;
        i -= i & -i;
    }
    return res;
}
signed main()
{
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    auto b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    map<int, int> mp;
    int cnt = 0;
    for (auto x : b) mp[x] = ++cnt;
    for (int i = 0; i < n; i++) a[i] = mp[a[i]];
    int ans = 0;
    cnt = 1ll;
    for (int i = 0; i < n; i++) {
        ans += ((qry(a[i] + 1) % p) * (cnt % p)) % p;
        ans %= p;
        cnt *= 2ll;
        cnt %= p;
        add(a[i] + 1, inv(cnt));
    }
    cout << ans;
    return 0;
}

