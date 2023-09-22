/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu 13 Apr 2023 04:42:00 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
struct node {
    int to, a, b;
};
vector<node> e[N];
int main () {
    int n, m, s; cin >> n >> m >> s;
    using P = pair<int, int>;
    for (int i = 0; i < m; i++) {
        int u, v, a, b; cin >> u >> v >> a >> b;
        e[u].push_back({v, a, b});
        e[v].push_back({u, a, b});
    }
    for (int i = 0; i < n; i++) {
        int c, d; cin >> c >> d;

    }
    return 0;
}
