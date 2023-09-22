/*************************************************************************
	> File Name: 1770c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jun 29 15:14:43 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n);
        set<int> st;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            st.insert(arr[i]);
        }
        if (st.size() < n) {
            cout << "NO\n";
            continue;
        }
        bool tmp = true;
        for (int i = 2; i <= n / 2 ; i++) {
            vector<int> cnt(i, 0);
            for (int j = 0; j < n; j++) {
                cnt[arr[j] % i]++;
            }
            bool flag = false;
            for (auto x : cnt) {
                if (x <= 1) {
                    flag = true;
                }
            }
            if (!flag) {
                tmp = false;
            }
        }
        if (tmp) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
