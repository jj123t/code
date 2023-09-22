#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) cin >> arr[i];
        priority_queue<int> q1, q2;
        for (int i = 1; i <= n; i += 2) q1.push(arr[i]);
        for (int i = 2; i <= n; i += 2) q2.push(arr[i]);
        int ans = -1e18;
        int t = 0;
        while (!q1.empty()) {
            t += q1.top();
            ans = max(ans, t);
            q1.pop();
        }
        t = 0;
        while (!q2.empty()) {
            t += q2.top();
            ans = max(ans, t);
            q2.pop();
        }
        cout << ans << "\n";
    }
    return 0;
}


