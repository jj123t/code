/*************************************************************************
	> File Name: 5343.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Aug 12 19:28:33 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
using mat = vector<vector<int>>;
using vet = vector<int>;
const int p = 1e9 + 7;
mat mul(mat a, mat b) {
    int n = a.size(), m = b[0].size();
    mat res = mat(n, vet(m, 0));
    for (int i = 0; i < a.size(); i++) {
        for (int k = 0; k < a[0].size(); k++) {
            for (int j = 0; j < b[0].size(); j++) {
                res[i][j] = (res[i][j] + (a[i][k] * b[k][j] % p)) % p;
            }
        }
    }
    return res;
}
mat mypow(mat &a, int b) {
    mat res = mat(a.size(), vet(a[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            res[i][j] = a[i][j];
        }
    }
    b--;
    while (b) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}
signed main()
{
    int n; cin >> n;
    set<int> a, b, c; 
    int lena; cin >> lena;
    for (int i = 0; i < lena; i++) {
        int x; cin >> x;
        a.insert(x);
    }
    int lenb; cin >> lenb;
    for (int i = 0; i < lenb; i++) {
        int x; cin >> x;
        b.insert(x);
    }
    for (auto x : a) {
        if (b.count(x)) {
            c.insert(x);
        }
    }

    mat res = mat(100, vet(100, 0));
    for (int i = 0; i < 100; i++) {
        if (c.count(i)) {
            res[0][i] = 1;
        }
    }
    for (int i = 1; i < 100; i++) res[i][]
    mat f = mat(100, vet(1, 0));
    f[0][0] = 1;
    for (int i = 1; i <= 99; i++) {
        for (auto x : c) {
            if (i - x >= 0) {
                f[i][0] = f[i][0] + f[i - x][0] % p;
            }
        }
    }
    mat ans = mul(mypow(res, n), f);
    if (n < 100) cout << f[n][0] << "\n";
    else cout << ans[0][0] << "\n";
    return 0;
}

