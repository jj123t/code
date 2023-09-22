/*************************************************************************
  > File Name: 12299.cpp
  > Author:123emm 
  > Mail: 2542142016@qq.com
  > Created Time: Sun Sep  3 11:56:57 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int INF = 1e9;
struct node {
    int v, tag;
} tree[N];
vector<int> res;
vector<int> dt(N);
map<int, int> mp;
vector<int> rt;
int m; 
void down(int p, int l, int r) {
    tree[p].v = min(tree[p * 2].v, tree[p * 2 + 1].v);
}
void build(int p, int l, int r) {
    if (l == r) tree[p].v = dt[l];
    else {
        int mid = l + r >> 1;
        build(p * 2, l, mid);
        build(p * 2 + 1, mid + 1, r);
        down(p, l, r);
    }
}
void shift(int p, int l, int r, int pos) {
    if (l == r and l == res[pos]) {
        tree[p].v = rt[(pos + 1) % m];
        return ;
    }
    int mid = l + r >> 1;
    if (res[pos] <= mid) shift(p * 2, l, mid, pos);
    if (res[pos] > mid) shift(p * 2 + 1, mid + 1, r, pos);
    down(p, l, r);
}
int qry(int p, int l, int r, int ql, int qr) {
    if (ql <= l and r <= qr) return tree[p].v;
    else {
        int mid = l + r >> 1;
        int ans = INF;
        if (ql <= mid)  ans = min(ans, qry(p * 2, l, mid, ql, qr)); 
        if (qr > mid) ans = min(ans, qry(p * 2 + 1, mid + 1, r, ql, qr));
        return ans;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> dt[i];
    build(1, 1, n);
    while (q--) {
        string s; cin >> s;
        if (s[0] == 's')  {

            int sz = s.size();
            s = s.substr(6, sz);
            s.pop_back();
            s += ",";
            string aph = "";
            vector<int> num;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == ',') {
                    int nb = 0;
                    reverse(aph.begin(), aph.end());
                    while (!aph.empty()) {
                        nb = nb * 10 + (aph.back() - '0');
                        aph.pop_back();
                    }
                    num.push_back(nb);
                }
                else {
                    aph += s[i];
                }
            }
            sort(num.begin(), num.end());
            res = num;
            m = num.size();
            rt = res;
            for (int i = 0; i < m; i++) {
                rt[i] = qry(1, 1, n, res[i], res[i]);
            }
            for (int i = 0; i < m; i++) {
                shift(1, 1, n, i);
            }

        }
        else {

            int sz = s.size();
            s = s.substr(6, sz);
            s.pop_back();
            s += ",";
            string aph = "";
            vector<int> num;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == ',') {
                    reverse(aph.begin(), aph.end());
                    int nb = 0;
                    while (!aph.empty()) {
                        nb = nb * 10 + (aph.back() - '0');
                        aph.pop_back();
                    }
                    num.push_back(nb);
                }
                else {
                    aph += s[i];
                }
            }
            sort(num.begin(), num.end());
            int l = num[0], r = num[1];
            cout << qry(1, 1, n, l, r) << "\n";
        }
    }
    return 0;
}

