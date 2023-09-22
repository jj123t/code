/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun May 28 02:03:22 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;

vector<int> e[9];
int bfs(vector<int> res) {
    vector<int> tp(9);
    for (int i = 0; i < 8; i++) tp[i] = i;
    tp[8] = -1;
    if (res == tp) return 1;
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> q;
    map<vector<int>, int> dis;
    q.push(make_pair(1, res));
    dis[res] = 1;
    while (!q.empty()) {
        auto [step, re] = q.top(); q.pop();
        if (step != dis[re]) continue; 
        for (int i = 0; i < 9; i++) {
            if (re[i] == -1) {
                for (auto v : e[i]) {
                    auto b = re; swap(b[i], b[v]);
                    if (!dis[b] || dis[b] > dis[re] + 1) {
                        dis[b] = dis[re] + 1; 
                        q.push(make_pair(dis[b], b));
                    }
                }
            }
        }
    }
    return dis[tp];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<int> loc(9, -1);
    for (int i = 0; i < 8; i++) {
        int r; cin >> r;
        r--;
        loc[r] = i;
    }
    cout << (bfs(loc) - 1);
    return 0;
}

