/*************************************************************************
	> File Name: a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue 02 May 2023 01:34:09 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n; cin >> n;
    vector<int> a(n), b(n), c(n - 1);
    int ans = 0;
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    for (auto &x : c) cin >> x;
    for (int i = 0; i < n; i++) {
        ans += b[a[i] - 1];
        if (i - 1 >= 0 && a[i] - a[i - 1] == 1) {
            ans += c[a[i - 1] - 1];
        }
    }
    cout << ans;
    return 0;
}
