/*************************************************************************
	> File Name: 5337.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Aug 16 17:55:08 2023
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
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int len = s.size();
    mat res = mat(26, vet(26, 1));
    mat a = mat(26, vet(26, 0));
    mat b = mat(26, vet(26, 0));
    for (int i = 0; i < 26; i++) a[0][i] = b[i][0] = 1;
    for (int i = 1; i < len; i++) res[s[i - 1] - 'a'][s[i] - 'a'] = 0;
    mat t = mul(a, mypow(res, n - 1));
    t = mul(t, b);
    cout << t[0][0] << "\n";
    return 0;
}

