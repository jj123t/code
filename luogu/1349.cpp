/*************************************************************************
	> File Name: 1349.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Aug 11 20:12:08 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
using mat = vector<vector<int>>;
using vet = vector<int>;
int mod = 1e9 + 7;
mat mul(mat a, mat b) {
    int n = a.size(), m = b[0].size();
    mat res = mat(n, vet(m, 0));
    for (int i = 0; i < a.size(); i++) {
        for (int k = 0; k < a[0].size(); k++) {
            for (int j = 0; j < b[0].size(); j++) {
                res[i][j] = (res[i][j] + (a[i][k] * b[k][j] % mod)) % mod;
            }
        }
    }
    return res;
}
mat mypow(mat &a, int b, mat &t) {
    while (b) {
        if (b & 1) t = mul(t, a);
        a = mul(a, a);
        b >>= 1;
    }
    return t;
}
signed main()
{
    int p, q, a1, a2, n; cin >> p >> q >> a1 >> a2 >> n >> mod;
    if (n == 1) {
        cout << a1;
        return 0;
    }
    if (n == 2) {
        cout << a2;
        return 0;
    }
    mat res = mat(2, vet(2, 0));
    res[0][0] = p, res[1][0] = q, res[0][1] = 1;
    mat t = mat(1, vet(2, 0));
    t[0][0] = a2, t[0][1] = a1;
    mat ans = mypow(res, n - 2, t);
    cout << ans[0][0] << "\n";
    return 0;
}

