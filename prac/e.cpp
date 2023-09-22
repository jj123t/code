/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu May 11 02:21:28 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, m, d; cin >> n >> m >> d;
        vector<int> arr(n + 1); 
        for (int i = 1; i <= n; i++) cin >> arr[i];
        int t = 0;
        priority_queue<int> q1;
        priority_queue<int, vector<int>, greater<int>> q2;
        int s = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            q1.push(arr[i]);
            while (!q1.empty() and q1.top() < 0) q1.pop();
            if (q2.size() < m) {
                if (!q1.empty()) {
                    s += q1.top();
                    q2.push(q1.top());
                    q1.pop();
                }
            }
            else if (!q2.empty() and q2.size() == m) {
                if (!q1.empty()) {
                    int resa = q1.top(); q1.pop();
                    int resb = q2.top(); q2.pop();
                    q2.push(max(resa, resb));
                    q1.push(min(resa, resb));
                    s -= resb;
                    s += max(resa, resb);
                }
            }
            t += d;
            ans = max(ans, s - t);
        }
        cout << ans << '\n';
    }
    return 0;
}

