/*************************************************************************
	> File Name: 3390.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Aug 11 13:25:14 2023
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
    int n, k; cin >> n >> k;
    mat res = mat(n, vet(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> res[i][j];
        }
    }
    res = mypow(res, k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

