/*************************************************************************
	> File Name: 3812.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Aug 12 21:34:23 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<int> a(60);
void insert(int x) {
    for (int i = 51; i >= 0; i--) {
        if (x >> i & 1) {
            if (!a[i]) {
                a[i] = x;
                return ;
            }
            else {
                x ^= a[i];
            }
        }
    }
}
bool check(int x) {
    for (int i = 51; i >= 0; i--) {
        if (x >> i & 1) {
            if (!a[i]) return false;
            else x ^= a[i];
        }
    }
    return true;
}
signed main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        insert(x);
    }
    int ans = 0;
    for (int i = 50; i >= 0; i--) {
        if (ans >> i & 1) continue;
        else {
            ans ^= a[i];
        }
    }
    cout << ans << "\n";
    return 0;
}

