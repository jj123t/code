/*************************************************************************
	> File Name: 3586.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Sep 10 20:04:08 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e6 + 10;
int n;
void add(int *tree, int i, int x) {
    while (i <= N) {
        tree[i] += x;
        i += (i & -i);
    }
}
int qry(int *tree, int i) {
    int res = 0;
    while (i) {
        res += tree[i];
        i -= (i & -i);
    }
    return res;
}
int z[N], g[N];
signed main()
{
    cin >> n;
    int q; cin >> q;
    vector<int> arr(n + 1);
    vector<pair<char, pair<int, int>>> ques(q);
    set<int> st;
    for (int i = 0; i < q; i++) {
        char c; int a, b; cin >> c >> a >> b;
        ques[i] = make_pair(c, make_pair(a, b));
        st.insert(b);
    }
    map<int, int> mp;
    int cnt = 0;
    for (auto x : st) mp[x] = ++cnt;

    for (int i = 0; i < q; i++) {
        auto [c, pp] = ques[i];
        if (c == 'U') {
            auto [k, a] = pp;
            if (arr[k] != 0) {
                add(g, mp[arr[k]], -arr[k]);
                add(z, mp[arr[k]], -1);
            }
            arr[k] = a;
            if (arr[k] != 0) {
                add(g, mp[arr[k]], arr[k]);
                add(z, mp[arr[k]], 1);
            }
        }
        else {
            auto [cc, ss] = pp;
            int d = qry(z, N - 1) - qry(z, mp[ss]);
                if (d * ss + qry(g, mp[ss]) >= cc * ss) {
                cout << "TAK\n";
            }
            else {
                cout << "NIE\n";
            }
        }
    }
    return 0;
}

