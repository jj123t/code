/*************************************************************************
	> File Name: 1737c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jun 22 05:17:00 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        using P = pair<int, int>;
        vector<P> arr(3);
        map<int, int> mpx, mpy;
        set<P> st;
        for (auto &[x, y] : arr) {
            cin >> x >> y;
            st.insert(P(x, y));
            mpx[x]++, mpy[y]++;
        }
        P t; cin >> t.first >> t.second;
        P s; 
        if (st.count(P(1, 1)) && st.count(P(1, 2)) && st.count(P(2, 1))) {
            if (t.first == 1 || t.second == 1) cout << "YES\n";
            else cout << "NO\n";
            continue;
        } 
        else if (st.count(P(1, n)) && st.count(P(2, n)) && st.count(P(1, n - 1))) {
            if (t.first == 1 || t.second == n) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        else if (st.count(P(n, 1)) && st.count(P(n - 1, 1)) && st.count(P(n, 2))) {
            if (t.first == n || t.second == 1) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        else if (st.count(P(n, n)) && st.count(P(n, n - 1)) && st.count(P(n -1, n))){
            if (t.first == n || t.second == n) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        for (auto r : mpx) {
            if (r.second == 1) s.first = r.first;
        }
        for (auto r : mpy) {
            if (r.second == 1) s.second = r.first;
        }
        if ((t.first - s.first) % 2 == 0 && (t.second - s.second) % 2 == 0) {
            cout << "NO\n";
        }
        else cout << "YES\n";
    }
    return 0;
}

