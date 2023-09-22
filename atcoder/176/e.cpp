/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun 16 Apr 2023 08:26:42 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int h, w, m; cin >> h >> w >> m;
    using P = pair<int, int>;
    vector<P> row(h), col(w);
    for (int i = 0; i < h; i++) row[i].second = i;
    for (int i = 0; i < w; i++) col[i].second = i;
    map<P, bool> mp;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        row[x].first++;
        col[y].first++;
        mp[P(x, y)] = true;
    }
    sort(row.rbegin(), row.rend());
    sort(col.rbegin(), col.rend());
    set<int> s1, s2;
    map<int, int> mp1, mp2;
    for (int i = 0; i < h; i++) {
        if (row[i].first == row[0].first) s1.insert(row[i].second);
    }
    for (int i = 0; i < w; i++) {
        if (col[i].first == col[0].first) s2.insert(col[i].second);
    }
    for (auto x : mp) {
        auto [a, b] = x.first;
         if (s1.count(a) && s2.count(b)) {
             mp1[a]++;
             mp2[b]++;
         }
    }
    for (auto c : s1) {
        if (mp1[c] != s2.size()) {
            cout << row[0].first + col[0].first;
            return 0;
        }
    }
    cout << row[0].first + col[0].first - 1;
    return 0;
}
