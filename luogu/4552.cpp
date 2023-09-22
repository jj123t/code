/*************************************************************************
	> File Name: 4552.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Aug 15 19:53:23 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> c(n + 1);
    int ta = 0, tb = 0;
    for (int i = 2; i <= n; i++) {
        c[i] = a[i] - a[i - 1];
        if (c[i] >= 0) ta += c[i];
        else tb += c[i];
    }
        cout << max(-tb, ta) << "\n" << abs(ta + tb) + 1 << "\n";
    return 0;
}

