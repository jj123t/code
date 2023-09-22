/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue 02 May 2023 03:05:56 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[i] = a[i - 1] + x;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += (a[i] <= k);
    }
    cout << ans;
    return 0;
}
