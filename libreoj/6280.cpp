/*************************************************************************
	> File Name: 6280.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul 17 14:25:54 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 5e5;
vector<int> arr(N);
vector<int> sid(N);
vector<int> s(N);
vector<int> lz(N);
vector<int> id(N);
int len;
void add(int l, int r, int val) {
    int sid = id[l], eid = id[r];
    if (sid == eid) {
        for (int i = l; i <= r; i++) arr[i] += val, s[sid] += val;
        return ;
    }
    for (int i = l; id[i] == sid; i++) arr[i] += val, s[sid] += val;
    for (int i = sid + 1; i < eid; i++) lz[i] += val, s[i] += val * len;
    for (int i = r; id[i] == eid; i--) arr[i] += val, s[eid] += val;
}
int qry(int l, int r, int p) {
    int sid = id[l], eid = id[r];
    int ans = 0;
    if (sid == eid) {
        for (int i = l; i <= r; i++) ans = (ans + lz[sid] + arr[i]) % p;
        return ans % p;
    }
    for (int i = l; id[i] == sid; i++) ans = (ans + lz[sid] + arr[i]) % p;
    for (int i = sid + 1; i < eid; i++) ans = (ans + s[i]) % p;
    for (int i = r; id[i] == eid; i--) ans = (ans + lz[eid] + arr[i]) % p;
    return ans % p;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n; cin >> n;
    len = sqrt(n);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        id[i] = (i - 1) / len + 1;
        s[id[i]] += arr[i];
    }
    for (int i = 1; i <= n; i++) {
        int opt, l, r, c; cin >> opt >> l >> r >> c;
        if (opt == 0) {
            add(l, r, c);
        }
        else {
            cout << qry(l, r, c + 1) << "\n";
        }
    }
    return 0;
}

