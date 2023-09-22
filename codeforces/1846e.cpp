/*************************************************************************
	> File Name: 1846e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul  8 00:34:39 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    vector<int>st(1000100, 0);
    vector<int>vis(1000100, 0);
    for (int i = 2; i <= 1000000; i++) {
        int s = 1;
        int k = i;
        s += k;
        st[s] = 1;
        while (s <= 1000000) {
            st[s] = 1;
            s += k;
            k = k * k;
        }
    }
    while (tt--) {
        int n; cin >> n;
        if (st[n]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

