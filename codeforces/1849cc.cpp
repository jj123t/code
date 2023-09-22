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
        vector<array<int, 3>> qry(m);
        for (int i = 0 ; i< m; i++) {
            int l, r; cin >> l >> r;
            qry[i] = {r, l, i};
        }
        sort(qry.begin(), qry.end());
        int j = 1;
        int ans = 0;
        vector<int> cnt(n + 1);
        for (int i = 0; i < m; i++) {
            auto [r, l, id] = qry[i];
            bool flag = false;
            int one = pfx[r].second - pfx[j - 1].second;
            if (one) flag = true;
            else flag= true;
            j = r;
            if (flag) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}


