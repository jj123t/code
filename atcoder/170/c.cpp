/*************************************************************************
	> File Name: c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat 15 Apr 2023 08:27:55 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;

    vector<multiset<int>> s(n);
    vector<set<int>> pos(200001);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i, j; cin >> i >> j;
            j--;
            s[j].insert(i);
            pos[i].insert(j);
        } else if (t == 2) {
            int i; cin >> i; i--;
            for (int v : s[i]) {
                cout << v << ' ';
            } cout << '\n';
        } else {
            int i; cin >> i;
            for (int v : pos[i]) {
                cout << v + 1 << ' ';
            }
            cout << '\n';
        }
    }
}
