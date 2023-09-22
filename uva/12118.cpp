/*************************************************************************
	> File Name: 12118.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Sep 19 22:20:09 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int par[100100];
void init(int n) { for (int i = 1; i <= n; i++) par[i] = i; }
int Find(int x) { if (x == par[x]) return x; return par[x] = Find(par[x]); }
void Unite(int x, int y) { par[Find(x)] = Find(y); }
signed main()
{
    int V, E, T; cin >> V >> E >> T; 
    int cnt = 0;
    while (!(V == 0 and E == 0 and T == 0)) {
        cnt++;
        init(V);
        vector<int> drgee(V + 1);
        for (int i = 1; i <= E; i++) {
            int u, v; cin >> u >> v;
            drgee[u]++, drgee[v]++;
            Unite(u, v);
        }
        if (E == 0) {
        cout << V << " " << E << " " << T << "\n";
            cout << "Case " << cnt << ":";
            cout << 0 << "\n";
        }
        else {
            set<int> st;
            map<int, vector<int>> mp;
            for (int i = 1; i <= V; i++) {
                st.insert(Find(i));
                mp[Find(i)].push_back(i);
            }
            int ans = E * T + ( (int)(st.size()) - 1) * T;
            for (auto [x, vt] : mp) {
                int res = 0;
                for (auto r : vt) {
                    if (drgee[r] % 2 == 1) res++;
                }
                if (res > 2)  ans += (res - 1) / 2 * T;
            }
            cout << "Case " << cnt << ":";
            cout << ans << "\n";
        }
        cin >> V >> E >> T;
    }
    return 0;
}

