/*************************************************************************
	> File Name: e.cpp
	> Author:123emm
	> Mail: 2542142016@qq.com
	> Created Time: Fri 14 Apr 2023 05:34:17 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
multiset<int> grd[N], st;
int main() {
    int n, q; cin >> n >> q;
    using P = pair<int, int>;
    vector<P> qry(n);
    int mn = 0;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        qry[i] = P(x, y);
        grd[y].insert(x);
        mn = max(mn, y);
    }
    for (int i = 1; i <= mn; i++) {
        if (grd[i].empty()) continue;
        st.insert(*(--(grd[i].end())));
    }
    while (q--) {
        int x, y; cin >> x >> y;
        if (!st.empty() && !grd[qry[x].second].empty()) {
            if (st.find(*(--(grd[qry[x].second].end()))) != (st.end())) {
                st.erase(st.find(*(--(grd[qry[x].second].end()))));
            }
        }
        if (!grd[qry[x].second].empty()) {
            if (grd[qry[x].second].find(qry[x].first) != (grd[qry[x].second].end())) {
                grd[qry[x].second].erase(grd[qry[x].second].find(qry[x].first));
            }
        }
        if (!grd[qry[x].second].empty()) {
            st.insert(*(--(grd[qry[x].second].end())));
        }
        if (!st.empty() && !grd[y].empty()) {
            if (st.find(*(--(grd[y].end()))) != (st.end())) {
                st.erase(st.find(*(--(grd[y].end()))));
            }
        }
        grd[y].insert(qry[x].first);
        qry[x].second = y;
        if (!grd[y].empty()) {
            st.insert(*(--(grd[y].end())));
        }
        cout << (*st.begin()) << "\n";
    }
}

