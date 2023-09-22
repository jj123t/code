/*************************************************************************
	> File Name: 1962.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Aug 11 18:52:28 2023
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
    mat res = mat(2, vet(2, 0));
    res[0][0] = res[0][1] = res[1][0] = 1;
    int n; cin >> n;
    res = mypow(res, n);
    cout << res[0][1] << "\n";
    return 0;
}

