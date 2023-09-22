/*************************************************************************
	> File Name: 1851e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul 25 22:20:42 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> cost(n + 1);
        for (int i = 1; i <= n; i++) cin >> cost[i];
        map<int, int> now;
        for (int i = 1; i <= k; i++) {
            int x; cin >> x;
            now[x] = true;
        }
        vector<int> e[n + 1];
        vector<int> inve[n + 1];
        vector<int> topu, drgee(n + 1);
        for (int i = 1; i <= n; i++) {
            int m; cin >> m;
            for (int j = 1; j <= m; j++) {
                int v; cin >> v;
                e[v].push_back(i);
                inve[i].push_back(v);
                drgee[i]++;
            }
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (drgee[i] == 0) {
                q.push(i);
                topu.push_back(i);
            }
        }
        while (!q.empty()) {
            auto u = q.front(); q.pop();
            for (auto v : e[u]) {
                if (--drgee[v] == 0) {
                    q.push(v);
                    topu.push_back(v);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (now[i]) cost[i] = 0;
        }
        vector<int> ans(n + 1);
        for (int i = 1; i <= n; i++) {
            int u = topu[i - 1];
            int a = cost[u];
            int b = 0;
            bool flag = false;
            for (auto v : inve[u]) {
                b += cost[v];
                flag = true;
            }
            if (flag)
                a = min(a, b);
            cost[u] = a;
            ans[u] = a;
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

