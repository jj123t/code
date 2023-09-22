/*************************************************************************
	> File Name: 1113.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul 27 20:17:21 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<int> e[n + 1];
    vector<int> inve[n + 1];
    vector<int> len(n + 1);
    vector<int> drgee(n + 1);
    for (int i = 1; i <= n; i++) {
        int id; cin >> id;
        cin >> len[id];
        int x; cin >> x;
        while (x != 0) {
            e[x].push_back(id);
            inve[id].push_back(x);
            drgee[id]++;
            cin >> x;
        }
    }
    queue<int> q;
    vector<int> topu;
    for (int i = 1; i <= n; i++) {
        if (!drgee[i]) {
            q.push(i);
            topu.push_back(i);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : e[u]) {
            if (--drgee[v] == 0) {
                topu.push_back(v);
                q.push(v);
            }
        }
    }
    vector<int> d(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int u = topu[i];
        int t = 0;
        for (auto v : inve[u]) {
            t = max(t, len[v]);
        }
        len[u] += t;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, len[i]);
    cout << ans << "\n";
    return 0;
}

