/*************************************************************************
	> File Name: 1778c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 14 21:19:40 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        string a, b; cin >> a >> b;
        set<char> st; map<int, char> mp;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                if (!st.count(a[i])) {
                    st.insert(a[i]);
                    mp[a[i]] = cnt++;
                } 
            }
        }
        if (k >= cnt) {
            cout << (long long)n * (n + 1) / 2 <<"\n";
            continue;
        }
        vector<int> p(cnt, 0); 
        for (int i = 0; i < k; i++) p[i] = 1;
        reverse(p.begin(), p.end());
        int ans = 0;
        do {
            int last = 0;
            int res = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] == b[i] or p[mp[a[i]]]) {
                    last++;
                    res += (last);
                }
                else {
                    last = 0;
                }
            }
            ans = max(ans, res);
        } while (next_permutation(p.begin(), p.end()));
        cout << ans << "\n";
    }
    return 0;
}

