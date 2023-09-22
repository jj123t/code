/*************************************************************************
	> File Name: 5960.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 28 12:59:36 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    vector<array<int, 3>> edge(m);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> v >> u >> w;
        edge[i] = {u, v, w};
    }
    vector<int> dis(n + 1, 0);
    auto f_n = [&]() -> bool {
        for (int i = 1; i <= n; i++) {
            for (auto [u, v, w] : edge) {
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    if (i == n - 1) return true;
                }
            }
        }
        return false;
    };
    if (f_n()) {
        cout << "NO\n";
    }
    else {
        for (int i = 1; i <= n; i++) {
            cout << dis[i] << " ";
        }
    }
    return 0;
}

