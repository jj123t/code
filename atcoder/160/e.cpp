/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed 12 Apr 2023 06:20:43 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
signed main () {
    int x, y, a, b, c;  cin >> x >> y >> a >> b >> c;
    vector<int> aar(a), bar(b), car(c);
    for (auto &x : aar) cin >> x;
    for (auto &x : bar) cin >> x;
    for (auto &x : car) cin >> x;
    sort(aar.rbegin(), aar.rend());
    sort(bar.rbegin(), bar.rend());
    sort(car.rbegin(), car.rend());
    using P = pair<int, int>;
    priority_queue<P> q; 
    for (int i = 0; i < min(x, a); i++) {
        q.push(P(aar[i], 1));
    }
    for (int i = 0; i < min(y, b); i++) {
        q.push(P(bar[i], 2));
    }
    int idx = 0;
    int ans = 0;
    int la = 0, lb = 0;
    while (!q.empty()) {
        if (q.size() <= c) {
            for (int i = 0; i < c; i++) {
                q.push(P(car[i], 0));
            }
            int d = x + y - la - lb;
            while (d--) {
                ans += q.top().first; q.pop();
            }
            cout << ans;
            return 0;
        }
        auto x = q.top(); q.pop();
        if (x.second == 1) {
            la++;
            ans += x.first;
        }
        else {
            lb++;
            ans += x.first;
        }
    }
    cout << ans;
    return 0;
}
