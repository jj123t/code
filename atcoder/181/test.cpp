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
    vector<int> A(n + 2);
    for (int i = 1; i <= n; i++) cin >> A[i];
    sort(A.begin() + 1, A.begin() + n + 1);
    set<int> st; 
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        st.insert(x);
    }
    int INF = 1e9;
    st.insert(-INF); st.insert(INF);
    vector<int> pfx(n, 0);
    pfx[0] = A[0];
    for (int i = 1; i < n; i++) pfx[i] = abs(A[i + 1] - A[i]);
    vector<int> init(n + 1, 0); 
    for (int i = 1; i < n; i++) {
        if (i - 1 >= 0) init[i + 1] = init[i - 1] + pfx[i];
    }
    int ans = INF;
    init.push_back(init[n]);
    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            int vala = init[i - 1];
            vala += init[n] - init[i];
            auto it = st.lower_bound(A[i]);
            int a = *it;
            --it;
            int b = *it;
            vala += min(abs(a - A[i]), abs(b - A[i]));
            ans = min(ans, vala);
        }
        else {
            int vala = abs(A[i - 1] - A[i + 1]);
            vala += init[i - 2] + init[n] - init[i];
            auto it = st.lower_bound(A[i]);
            int a = *it;
            --it;
            int b = *it;
            vala += min(abs(a - A[i]), abs(b - A[i]));
            ans = min(vala, ans);
        }
    }
    cout << ans << "\n";
    return 0;
}
}
