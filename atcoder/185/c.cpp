/*************************************************************************
	> File Name: c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri 21 Apr 2023 01:08:52 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
int C(int a, int b) {
    int ans = 1;
    for (int i = 0; i < b; i++) {
        ans = ans * (a - 1 - i) / (i + 1);
    }
    return ans;
}
signed main () {
    int n; cin >> n;
    cout << C(n, 11);
    return 0;
}
