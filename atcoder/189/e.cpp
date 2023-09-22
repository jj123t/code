/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun 23 Apr 2023 10:00:39 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
signed main () {
    int n; cin >> n;
    using P = pair<int, int>;
    using AR = array<int, 3>;
    vector<P> point(n); 
    for (auto &[a, b] : point) cin >> a >> b;

    int m; cin >> m;
    vector<pair<AR, AR>> pfxoption(m + 1); 
    pfxoption[0].first[0] = 1; pfxoption[0].second[1] = 1;

    for (int i = 0; i < m; i++) {
        int x, y; 
        cin >> x; if (x == 3 || x == 4) cin >> y;
        auto cur = pfxoption[i];
        if (x == 1) {
            swap(cur.first, cur.second);
            for (int j = 0; j < 3; j++) {
                cur.second[j] *= -1;
            }
        }
        else if (x == 2) {
            swap(cur.first, cur.second);
            for (int j = 0; j < 3; j++) {
                cur.first[j] *= -1;
            }
        }
        else if (x == 3) {
            for (int j = 0; j < 3; j++) {
                cur.first[j] *= -1;
            }
            cur.first[2] += 2 * y;
        }
        else {
            for (int j = 0; j < 3; j++) {
                cur.second[j] *= -1;
            }
            cur.second[2] += 2 * y;
        }
        pfxoption[i + 1] = cur;
    }

    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        b--;
        auto [x, y] = point[b];
        auto cur = pfxoption[a];
        int A = x * cur.first[0] + y * cur.first[1] + cur.first[2];
        int B = x * cur.second[0] + y * cur.second[1] + cur.second[2];
        cout << A << " " << B << "\n";
    }
    return 0;
}
