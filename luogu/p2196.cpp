/*************************************************************************
	> File Name: p2196.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed 26 Apr 2023 08:29:50 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
signed main () {
    int n; cin >> n;
    vector<int> w(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> w[i];
    vector<vector<int>> e(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i < n; i++)  {
        for (int j = i + 1; j <= n; j++) {
            cin >> e[i][j];
        }
    }
    int ans = 0;
    int idx = 0;
    vector<int> f(n + 1, 0);
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (e[j][i] == 1 && f[j] > f[i]) {
                f[i] = f[j];
                pre[i] = j;
            }
        }
        f[i] += w[i];
        if (f[i] > ans) {
            ans = f[i];
            idx = i;
        }
    }
    stack<int> st;
    while (idx) {
        st.push(idx);
        idx = pre[idx];
    }
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
    cout << ans;
    return 0;
}
