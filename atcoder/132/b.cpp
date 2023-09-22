/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue 02 May 2023 02:42:35 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n; cin >> n;
    vector<int> p(n);
    for (auto &a : p) cin >> a;
    int ans = 0;
    for (int i = 1; i <= n - 2; i++) {
        int a = min(p[i - 1], p[i + 1]);
        int b = max(p[i - 1], p[i + 1]);
        if (p[i] >= a && p[i] <= b) ans++;
    }
    cout << ans;
    return 0;
}
