/*************************************************************************
	> File Name: 1808c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul 12 18:00:06 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
using ll = long long; 
vector<int> lef(20);
vector<int> righ(20);
map<string, pair<int, int>> mt; 
string check(string a, string b) {
    if (a == "") return b;
    if (b == "") return a;
    int mi = 9, mx = 0;
    if (mt.count(a)) {
        auto [x, y] = mt[a];
        mx = x, mi = y;
    }
    else {
        for (auto c : a) mi = min(mi, (c - '0')), mx = max(mx, (c - '0'));
        mt[a] = {mx, mi};
    }
    int aa = mx - mi;
    mi = 9, mx = 0;
    if (mt.count(b)) {
        auto [x, y] = mt[b];
        mx = x, mi = y;
    }
    else  {
        for (auto c : b) mi = min(mi, (c - '0')), mx = max(mx, (c - '0'));
        mt[b] = {mx, mi};
    }
    int bb = mx - mi;
    if (aa > bb) return b;
    else return a;
}
map<string, string> mp;
string dfs(ll idx, ll l, ll r, string st) {
    if (idx == 0) {
        reverse(st.begin(), st.end());
        while (!st.empty() and st.back() == '0') st.pop_back();
        if (st.empty()) st = "0";
        reverse(st.begin(), st.end());
        return st;
    }
    if (!l and !r and mp[st].size()) return mp[st]; 
    int lb = (l ? lef[idx] : 0);
    int ub = (r ? righ[idx] : 9);
    string ans = "";
    for (int i = lb; i <= ub; i++) {
        ans = check(ans, dfs(idx - 1, l && i == lb, r && i == ub, st + (char)(i + '0')));
    }
    if (!l and !r) mp[st] = ans;
    return  ans;
}
string solve(ll l, ll r) {
    fill(lef.begin(), lef.end(), 0);
    fill(righ.begin(), righ.end(), 0);
    int cnt = 0;
    while (l) {
        lef[++cnt] = l % 10;
        l /= 10;
    }
    cnt = 0;
    while (r) {
        righ[++cnt] = r % 10;
        r /= 10;
    }
    return dfs(cnt, 1, 1, "");
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        ll a, b; cin >> a >> b;
        string s1 = to_string(a), s2 = to_string(b);
        if (s1.size() < s2.size()) {
            for (int i = 0; i < s1.size(); i++) {
                cout << 9 ;
            }
            cout << "\n";
            continue;
        } 
        cout << solve(a, b) << "\n";
    }
    return 0;
}

