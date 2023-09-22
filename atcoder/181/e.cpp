/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed 19 Apr 2023 07:48:49 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
signed main () {
    int n, m; cin >> n >> m;
    vector<int> A(n + 2, 0); 
    for (int i = 1; i <= n; i++) cin >> A[i];
    sort(A.begin() + 1, A.begin() + n + 1);
    set<int> st;
    int INF = 1e18;
    A[0] = 0, A[n + 1] = INF;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        st.insert(x);
    }
    vector<int> pfx(n + 1, 0);
    int ans = INF;
    for (int i = 2; i <= n; i++) {
        pfx[i] += pfx[i - 2] + abs(A[i] - A[i - 1]);
    }
    for (auto x : st) {
        int it = lower_bound(A.begin(), A.begin() + n + 1, x) - A.begin();
        if (it & 1) {
            int val = abs(x - A[it]);
            val += pfx[n] - pfx[it];
            val += pfx[it - 1];
            ans = min(ans, val);
        }
        else {
            it--;
            int val = abs(x - A[it]);
            val += pfx[it - 1] + pfx[n] - pfx[it];
            ans = min(ans, val);
        }
    }
    cout << ans;
    return 0;
}
