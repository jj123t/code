/*************************************************************************
	> File Name: 1621.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Aug 18 16:36:46 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
vector<int> par(1e6);
void init(int n) {
    for (int i = 1; i <= n; i++) par[i] = i;
}
int Find(int x) {
    if (x == par[x]) return x;
    else return par[x] = Find(par[x]);
}
void Unite(int x, int y) {
    par[Find(x)] = Find(y);
}
bool Same(int x, int y) {
    return Find(x) == Find(y);
}
int main()
{
    int a, b, p; cin >> a >> b >> p;
    init(b + 1);
    vector<int> vis(b + 1);
    vector<int> e;
    for (int i = 2; i <= b; i++) {
        if (!vis[i]) {
            if (p <= i) e.push_back(i);
        }
        for (int j = 2 * i; j <= b; j += i) vis[j] = true;
    }
    for (auto d : e) {
        int idx = 0;
        for (int j = d; j <= b; j += d) {
            if (a <= j and j <= b) {
                if (!idx) idx = j;
                else Unite(idx, j);
            }
        }
    }
    set<int> st;
    for (int i = a; i <= b; i++) {
        st.insert(Find(i));
    }
    cout << st.size() << "\n";
    return 0;
}

