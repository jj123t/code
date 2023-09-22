/*************************************************************************
	> File Name: 2672.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Aug 14 21:34:25 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n; cin >> n;
    using P = pair<int, int>;
    vector<P> a(n + 1);
    vector<int> s(n + 1);
    vector<int> q(n + 1);
    vector<int> h(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i].second;
    for (int i = 1; i <= n; i++) cin >> a[i].first;
    sort(a.begin() + 1, a.end());
    reverse(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i].first;
    for (int i = 1; i <= n; i++) q[i] = max(q[i - 1], 2 * a[i].second);
    for (int i = n; i >= 1; i--) h[i] = max(h[i + 1], 2 * a[i].second + a[i].first);
    for (int i = 1; i <= n; i++) {
        cout << max(s[i] + q[i], s[i - 1] + h[i]) << "\n";
    }
    return 0;
}

