/*************************************************************************
	> File Name: 5353.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Sep 10 11:59:51 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
string s, t;
int tax[N], sa[N], rnk[N], tp[N], par[N];
int n, M;
vector<int> e[N];
void Qsort() {
    for (int i = 1; i <= M; i++) tax[i] = 0;
    for (int i = 1; i <= n; i++) tax[rnk[i]]++;
    for (int i = 1; i <= M; i++) tax[i] += tax[i - 1];
    for (int i = n; i >= 1; i--) sa[tax[rnk[tp[i]]]--] = tp[i];
}
void SA() {
    M = 122;
    for (int i = 1; i <= n; i++) rnk[i] = s[i] - 'a' + 1, tp[i] = i;
    Qsort();
    for (int w = 1, p = 0; p < n; M = p, w <<= 1) {
        p = 0;
        for (int i = 1; i <= w; i++) tp[++p] = n - w + i;
        for (int i = 1; i <= n; i++) if (sa[i] > w) tp[++p] = sa[i] - w;
        Qsort();
        swap(tp, rnk); 
        rnk[sa[1]] = p = 1;
        for (int i = 2; i <= n; i++) {
            rnk[sa[i]] = (tp[sa[i]] == tp[sa[i - 1]] and tp[sa[i] + w] == tp[sa[i - 1] + w]) ? p : ++p;
        }
    }
}
void dfs(int u) {
    s += t[u];
    for (auto v : e[u]) {
        if (v != par[u]) {
            dfs(v);
        }
    }
}
int main()
{
    int V; cin >> V;
    for (int i = 2; i <= V; i++) {
        int U; cin >> U;
        par[i] = U;
        e[U].push_back(i);
        e[i].push_back(U);
    }
    cin >> t;
    t = " " + t;
    dfs(1);
    reverse(s.begin(), s.end());
    n = s.size();
    s = " " + s;
    SA();
    cout << s << "\n";
    for (int i = 1; i <= n; i++) {
        cout << sa[i] << ' ';
    }
    return 0;
}

