/*************************************************************************
	> File Name: 3275.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 28 13:47:18 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k; cin >> n >> k;
    vector<array<int, 3>> e;
    for (int i = 1; i <= k; i++) {
        int op, u, v; cin >> op >> u >> v;
        if (op == 1) {
            e.push_back({u, v, 0});
            e.push_back({v, u, 0});
        }
        else if (op == 2) {
            e.push_back({v, u, -1});
        }
        else if (op == 3) {
            e.push_back({v, u, 0});
        }
        else if (op == 4) {
            e.push_back({u, v, -1});
        }
        else if (op == 5) {
            e.push_back({u, v, 0});
        }
    }
    vector<int> dis(n + 1);
    auto f_n = [&]() -> bool {
        for (int i = 1; i <= n; i++) {
            for (auto [u, v, w] : e) {
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    if (i == n - 1) return true;
                }
            }
        }
        return false;
    };
    if (f_n()) cout << -1 << "\n";
    else {
        int mi = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            mi = min(mi, dis[i]);
            ans += dis[i];
        }
        mi = abs(mi) + 1;
        ans += mi * n;
        cout << ans << "\n";
    }
    return 0;
}

