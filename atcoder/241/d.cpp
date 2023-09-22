/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed May 31 02:17:01 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define int long long 
signed main()
{
    int qq; cin >> qq;
    set<int> st;
    map<int, int> mp;
    while (qq--) {
        int op; cin >> op; 
        int x; cin >> x;
        if (op == 1) {
            st.insert(x);
            mp[x]++;
        }
        else if (op == 2) {
            int k; cin >> k;
            auto it = st.lower_bound(x);
            while ((*it) > x && it != st.begin()) it--;
            if ((*it) > x) {
                cout << -1 << '\n';
                continue;
            }
            while (k) {
                if (k - mp[(*it)] >= 0) {
                    k -= mp[(*it)]; 
                    if (k == 0) break;
                    if (it == st.begin()) {
                        break;
                    }
                    else it--;
                }
                else {
                    k = 0;
                    break;
                }
            }
            if (k) cout << -1 << "\n";
            else cout << (*it) << "\n";
        }
        else {
            int k; cin >> k;
            auto it = st.lower_bound(x);
            if (it == st.end()) {
                cout << -1 << "\n";
                continue;
            }
            while (k) {
                if (k - mp[(*it)] >= 0) { 
                    k -= mp[(*it)];
                    if (k == 0) break;
                    if (++it == st.end()) {
                        break;
                    }
                }
                else {
                    k = 0;
                    break;
                }
            }
            if (k) cout << -1 << "\n";
            else cout << (*it) << "\n";
        }
    }
    return 0;
}

