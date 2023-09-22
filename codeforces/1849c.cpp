/*************************************************************************
	> File Name: 1849c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul 27 22:24:38 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
using std::string;

const int M = 32212254719;
const int B = 31;
const int N = 1e6;
#define db long double

int mypow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res % M) * (a % M) % M;
        a = a * a % M;
        b >>= 1;
    }
    return res % M;
}
signed main()
{

    vector<int> fac(N);
    for (int i = 1; i <= 2e5 + 10; i++) {
        fac[i] = (fac[i - 1] + mypow(B, i) % M) % M;
    }
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        string s; cin >> s;
        using P = pair<int, int>;
        vector<P> pfx(n + 1);
        for (int i = 1; i <= n; i++) {
            pfx[i].first = pfx[i - 1].first + (s[i - 1] == '1');
            pfx[i].second = pfx[i - 1].second + (s[i - 1] == '0');
        }
        vector<int> Hash(n + 1);
        for (int i = 1; i <= n; i++) {
            int x = 0;
            if (s[i - 1] == '0') x = 17;
            if (s[i - 1] == '1') x = 233;
            Hash[i] = (Hash[i - 1] + (x * mypow(B, i) % M)) % M;
        }
        set<int> st;
        for (int i = 1; i <= m; i++) {
            int l, r; cin >> l >> r;
            int zero = pfx[r].second - pfx[l - 1].second;
            int one = pfx[r].first - pfx[l - 1].first;
            int res = (233ll * (fac[r] % M - fac[l + zero - 1] % M + M) % M) % M;
            int res2 = (17ll * (fac[l + zero - 1] - fac[l - 1] + M) % M) % M;
            res = (res + res2) % M;
            int a = Hash[l - 1] % M;
            int b = (Hash[n] % M - Hash[r] % M + M) % M;
            int c = (a + b) % M;
            int tmp = (res + c) % M;
            st.insert(tmp);
        }
        cout << st.size() << "\n";
    }
    return 0;
}

