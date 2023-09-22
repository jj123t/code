/*************************************************************************
	> File Name: 1939.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Aug 11 18:03:13 2023
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
    mat res = mat(3, vet(3, 0));
    res[0][0] = res[0][2] = res[1][0] = res[2][1] = 1;
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        if (n <= 3) {
            cout << 1 << "\n";
            continue;
        }
        auto t = res;
        t = mypow(t, n);
        cout << t[1][0] % p << "\n";
    }
    return 0;
}

