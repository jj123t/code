/*************************************************************************
	> File Name: 1848b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jul 16 22:57:47 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            arr[i]--;
        }
        using P = pair<int, int>;
        set<P> st;
        int ls = n;
        int mx = 0;
        for (int i = n - 1; i > -1; i--) {
            if (arr[i] == arr[0]) {
                mx = max(mx, ls - i - 1);
                st.insert({i + 1, mx});
                ls = i;
            }
        }
        for (auto [x, y] : st) {
            cout << x << " " << y << '\n';
        }
        cout << "\n";
        vector<int> ans(m + 1);
        vector<int> last(m + 1);
        last[arr[0]] = 0;
        for (int i = 1; i < n; i++) {
            auto it = st.lower_bound(P(i, 0));
            --it; auto j = *it;
            int a = i - j.first - 1;
            int b = i - last[arr[i]] - 1;
            int d = min(a, b);
            ans[arr[i]] = max(ans[arr[i]], d);
            last[arr[i]] = i + 1;
        }
        for (int i = 1; i <= m; i++) {
            auto it = st.lower_bound(P(last[i], 0));
            auto j = *it;
            int d = min(j.first - last[i] - 1, j.second);
            ans[i] = max(d, ans[i]);
        }
        for (int i = 0; i <= m; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

