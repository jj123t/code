/*************************************************************************
	> File Name: 2294.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 28 13:46:50 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<array<int, 3>> edge;
        for (int i = 1; i <= m; i++) {
            int u, v, w; cin >> u >> v >> w;
            edge.push_back({u - 1, v, w});
            edge.push_back({v, u - 1, -w});
        }
        vector<int> d(n + 1);
        auto f = [&]() -> bool {
            for (int i = 1; i <= n; i++) {
                for (auto [u, v, w] : edge) {
                    if (d[v] > d[u] + w) {
                        d[v] = d[u] + w;
                        if (i == n - 1) return true;
                    }
                }
            }
            return false;
        };
        if (f()) cout << "false" << "\n";
        else cout << "true" << "\n";
    }
    return 0;
}

