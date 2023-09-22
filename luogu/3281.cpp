/*************************************************************************
	> File Name: 3281.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Aug  6 22:08:39 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int p = 20130427;
int B, m;
int a[1100000], pfx[1100000];
int mypow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
using tp = tuple<int, int, int>;
map<tp, int> dp;
int dfs(int idx, int lim, int s, int leadzero, int st) {
    if (idx == 0) return s % p;
    if (!lim and !leadzero and dp[tp(idx, st, s)]) return dp[tp(idx, st, s)];
    int ub = (lim ? a[idx] : B - 1);
    int ans = 0;
    for (int i = 0; i <= ub; i++) {
        ans += dfs(idx - 1, lim && i == ub, ((s % p) + (((leadzero) ? 1 : st - idx + 1) * (pfx[idx - 1] * i % p) % p) % p), leadzero && i == 0, (leadzero && i != 0) ? idx : st);
        ans %= p;
    }
    if (!lim and !leadzero) dp[tp(idx, st, s)] = ans;
    return ans;
}
int solve(vector<int> s) {
    int cnt = 0;
    reverse(s.begin(), s.end());
    for (auto c : s) {
        a[++cnt] = c;
    }
    m = cnt;
    return dfs(cnt, 1, 0, 1, m) % p;
}
void sub(vector<int> &x) {
    reverse(x.begin(), x.end());
    int idx = 0;
    while (x[idx] == 0) idx++;
    x[idx]--;
    for (int i = 0; i < idx; i++) x[i] = B - 1;
    while (!x.empty() and x.back() == 0) x.pop_back();
    reverse(x.begin(), x.end());
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> B;

    pfx[0] = 1;
    for (int i = 1; i <= 101000; i++) pfx[i] = (pfx[i - 1] + mypow(B, i)) % p;

    int lena; cin >> lena;
    vector<int> resa;
    for (int i = 0; i < lena; i++) {
        int x; cin >> x;
        resa.push_back(x);
    }
    if (resa[0] != 0) sub(resa);

    int ansa = solve(resa);

    int lenb; cin >> lenb;
    vector<int> resb;
    for (int i = 0; i < lenb; i++) {
        int x; cin >> x;
        resb.push_back(x);
    }
    int ansb = solve(resb);

    int d = (((ansb - ansa) % p) + p) % p;
    cout << d << "\n";

    return 0;
}

