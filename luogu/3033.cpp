/*************************************************************************
	> File Name: 3033.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Aug  3 23:08:30 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 500;
int vis[N], match[N];
vector<int> e[N];
bool dfs(int u) {
    for (auto v : e[u]) {
        if (vis[v]) continue;
        vis[v] = true;
        if (!match[v] or dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}
using P = pair<int, int>;
void print(P a) {
    cout << a.first << " -- " << a.second << "\n";
}
bool check(P a, P b, P c, P d) {
    if (a.second > b.second) swap(a, b);
    if (c.first > d.first) swap(c, d);
    if ((a.second <= c.second and c.second <= b.second) and (c.first <= a.first and a.first <= d.first)) {
        return false;
    }
    return true;
}

int main() 
{
    int n; cin >> n;
    vector<array<P, 2>> arr, brr;
    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            arr.push_back({P(x1, y1), P(x2, y2)});
        }
        if (y1 == y2) {
            brr.push_back({P(x1, y1), P(x2, y2)});
        }
    }
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < brr.size(); j++) {
            if (!check(arr[i][0], arr[i][1], brr[j][0], brr[j][1])) {
                e[i + 1].push_back(arr.size() + j + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        fill(vis, vis + n + 1, 0);
        if (dfs(i)) ans++;
    }

    cout << n - ans << "\n";
    return 0;
}

