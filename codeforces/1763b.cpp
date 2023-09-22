/*************************************************************************
	> File Name: 1763b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jul  2 15:11:44 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        using P = pair<int, int>;
        vector<P> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i].first;
        for (int j = 0; j < n; j++) cin >> arr[j].second;
        priority_queue<P, vector<P>, greater<P>> q;
        set<int> st; map<int, int> mp;
        for (int i = 0; i < n; i++) {
            q.push(arr[i]);
            mp[arr[i].second]++;
            st.insert(arr[i].second);
        }
        int tmp = k;
        int last = 0;
        while (!q.empty()) {
            while (!q.empty() && q.top().first - last <= tmp) {
                mp[q.top().second]--;
                if (mp[q.top().second] == 0) {
                    st.erase(q.top().second);
                }
                q.pop();
            }
            if (q.empty()) break;
            last += tmp;
            tmp -= (*st.begin());
            if (tmp <= 0) break;
        }
        if (tmp >= 0 && q.empty()) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}

