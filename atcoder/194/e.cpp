/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri 28 Apr 2023 05:38:19 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define int long long 
signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for (auto &a : arr) cin >> a;
    set<int> st;
    map<int, int> mp;
    for (int i = 0; i <= n; i++) st.insert(i);
    for (int i = 0; i < m; i++) {
        mp[arr[i]]++;
        if (mp[arr[i]] == 1) st.erase(arr[i]);
    }
    int ans = *st.begin();
    for (int i = m, left = 0; i < n; i++) {
        int a = arr[left++];
        int b = arr[i];
        if (mp[b] == 0) {
            st.erase(b);
        }
        mp[b]++;
        mp[a]--;
        if (mp[a] == 0) st.insert(a);
        ans = min(ans, (*st.begin()));
    }
    cout << ans;
    return 0;
}

