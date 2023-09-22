/*************************************************************************
	> File Name: 1972.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul 24 22:14:55 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
using P = pair<int, int>;
vector<int> tree(N);
vector<P> e[N]; 
vector<int> arr(N);
vector<int> ans(N);
vector<int> color(N);

int n;

void add(int i, int x) {
    while (i <= n) {
        tree[i] += x;
        i += (i & -i);
    }
}
int qry(int i) {
    int res = 0;
    while (i) {
        res += tree[i];
        i -= (i & -i);
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        e[r].push_back(P(l, i));
    }
    for (int i = 1; i <= n; i++) {
        int c = arr[i];
        if (color[c]) {
            add(color[c], -1);
            color[c] = i;
            add(i, 1);
        }
        else {
            color[c] = i;
            add(i, 1);
        }
        for (auto [l, id] : e[i]) {
            ans[id] = qry(i) - qry(l - 1);
        }
    }
    for (int i = 0; i < m; i++) cout << ans[i] << "\n";
    return 0;
}

