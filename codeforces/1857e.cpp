/*************************************************************************
	> File Name: 1857e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Aug  7 22:19:33 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n + 1);
        map<int, int> mp;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        using P = pair<int, int>;
        set<int> st;
        vector<int> re[n + 1];
        for (int i = 1; i <= n; i++) {
            st.insert(arr[i]);
            mp[arr[i]]++;
        }
        auto brr = arr;
        int cnt = 0;
        map<int, int> pp;
        for (auto x : st) {
            arr[++cnt] = x;
            pp[x] = cnt;
        }
        for (int i = 1; i <= n; i++) {
            re[pp[brr[i]]].push_back(i);
        }
        vector<int> pfx(cnt + 1), suf(cnt + 2);

        pfx[2] = (arr[2] - arr[1] + 1) * mp[arr[1]];
        int idx = mp[arr[2]] * mp[arr[1]];
        for (int i = 3; i <= cnt; i++) {
        }
        reverse(arr.begin() + 1, arr.begin() + cnt + 1);

        suf[2] = (arr[1] - arr[2] + 1) *  mp[arr[1]];
        idx = mp[arr[2]] * mp[arr[1]];
        for (int i = 3; i <= cnt; i++) {
        }
        vector<int> f(n + 1);
        for (int i = 1; i <= cnt; i++) {
            cout << suf[i] << "\n";
        }
        for (int i = 1; i <= cnt; i++) {
            int x = arr[i];
            int ans = pfx[i] + suf[cnt - i] + mp[arr[i]] - 1;
            for (auto id : re[i]) {
                f[id] = ans;
            }
            //cout << ans << "\n";
        }
        for (int i = 1; i <= n; i++) {
            cout << f[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

