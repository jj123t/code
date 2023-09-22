/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue 02 May 2023 02:47:08 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n, k; cin >> n >> k;
    int tmp = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = k + i;
        tmp += a[i];
    }
    int mx = 1e9;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int res = tmp - a[i];
        if (abs(res - tmp) < mx) {
            mx = abs(res - tmp);
            ans = res;
        }
    }
    cout << ans;
    return 0;
}
