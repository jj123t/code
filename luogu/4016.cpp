/*************************************************************************
	> File Name: 4016.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Aug 16 19:35:11 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    int s = 0;
    for (int i = 1; i <= n; i++) { cin >> a[i]; s += a[i]; }
    s /= n; 
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) a[i] -= s, p[i] = p[i - 1] + a[i]; 
    sort(p.begin() + 1, p.begin() + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += abs(p[n / 2 + 1] - p[i]);
    }
    cout << ans << "\n";
    return 0;
}

