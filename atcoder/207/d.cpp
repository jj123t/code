/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed May  3 21:36:16 2023
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n; cin >> n;
    if (n == 1) {
        cout << "Yes\n";
        return 0;
    }
    vector<int> arra(n), arrb(n), brra(n), brrb(n);
    for (int i = 0; i < n; i++) {
        cin >> arra[i] >> arrb[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> brra[i] >> brrb[i];
    }
    using P = pair<int, int>;
    auto f = [&](vector<int> a, vector<int> b, int x, int y) {
        multiset<P> st;
        int u = a[y] - a[x];
        int v = b[y] - b[x];
        for (int i = 0; i < n; i++) {
            int ru = a[i] - a[x];
            int rv = b[i] - b[x];
            st.insert(P(ru * u + rv * v, rv * u - ru * v));
        }
        return st;
    };
    auto fa = f(arra, arrb, 0, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            auto fb = f(brra, brrb, i, j);
            if (fa == fb) {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
    return 0;
}

