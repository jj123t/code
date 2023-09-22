/*************************************************************************
	> File Name: 1779c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul  6 21:12:50 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
using ll = long long ;
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        priority_queue<ll, vector<ll>, greater<ll>> q2;
        priority_queue<ll, vector<ll>, less<ll>> q1;
        int ans = 0;
        int s = 0;
        for (int i = m - 1; i >= 1; i--) {
            s += arr[i];
            q1.push(arr[i]);
            while (s > 0) {
                s -= 2 * q1.top(); q1.pop();
                ans++;
            }
        }
        s = 0;
        for (int i = m; i < n; i++) {
            s += arr[i];
            q2.push(arr[i]);
            while (s < 0) {
                s -= 2 * q2.top(); q2.pop();
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

