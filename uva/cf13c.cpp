/*************************************************************************
	> File Name: cf13c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Sep 18 20:34:17 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    priority_queue<int> q;
    int ans = 0;
    q.push(a[1]);
    for (int i = 2; i <= n; i++) {
        int x = a[i];
        q.push(x);
        if (q.top() > x) {
            ans += q.top() - x;
            q.pop();
            q.push(x);
        }
    }
    cout << ans << "\n";
    return 0;
}

