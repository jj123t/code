/*************************************************************************
	> File Name: fleury.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Sep 20 13:01:48 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
vector<int> edges[N];
vector<int> hierholzer(int u) {
    stack<int> path;
    vector<int> circuit;
    int current = u;
    path.push(u);
    while (!path.empty()) {
        if (edges[current].size()) {
            path.push(current);
            int next = edges[current][0];
            edges[current].erase(edges[current].begin());
            //edges[next].erase(current);
            current = next;
        }
        else {
            circuit.push_back(current);
            current = path.top();
            path.pop();
        }
    }
    return circuit;
}
int main()
{
    int n, m;  cin >> n >> m;
    vector<int> in(n + 1), out(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        in[v]++, out[u]++;
        edges[u].push_back(v);
        //edges[v].insert(u);
    }
    map<int, int> drgee;
    int start = 1;
    for (int i = 1; i <= n; i++) {
        drgee[out[i] - in[i]]++;
        if (out[i] - in[i] == 1) start = i; 
    }
    if (!((drgee[1] == 1 and drgee[-1] == 1) or (drgee[1] == 0 and drgee[-1] == 0))) {
        cout << "No\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) sort(edges[i].begin(), edges[i].end());
    auto path = hierholzer(start);
    reverse(path.begin(), path.end());
    for (auto x : path) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}

