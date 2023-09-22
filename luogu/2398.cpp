/*************************************************************************
	> File Name: 2398.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Aug  1 17:35:30 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n; cin >> n;
    vector<int> phi(n + 1);
    for (int i = 1; i <= n; i++) phi[i] = i;
    int ans = 0; // sum(  phi(d) | d\n ) == n
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) {
                phi[j] = phi[j]  / i * (i - 1);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ans += phi[i] * (n / i) * (n / i);
    }
    cout << ans << "\n";
    return 0;
}

