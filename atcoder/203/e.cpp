/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed May  3 10:31:24 2023
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n, m; cin >> n >> m;
    map<int, vector<int>> mp;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        mp[x].push_back(y);
    }
    set<int> st;
    st.insert(n);
    for (auto [x, ys] : mp) {
        vector<int> r;
        for (auto y : ys) {
            for (auto d : {-1, 1}) {
                if (st.count(y + d)) {
                    r.push_back(y);
                }
            }
        }
        for (auto y : ys) st.erase(y);
        for (auto y : r) st.insert(y);
    }
    cout << st.size();
    return 0;
}

