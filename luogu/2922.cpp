/*************************************************************************
	> File Name: 2922.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jul 30 21:58:46 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 5e6 + 10;
int trie[N][2];
int exist[N];
int ed[N];
int cnt = 0;
void insert(string s) {
    int p = 0;
    for (auto c : s) {
        int x = c - '0';
        if (!trie[p][x]) trie[p][x] = ++cnt;
        p = trie[p][x];
        exist[p]++;
    }
    ed[p]++;
}
int qry(string s) {
    int p = 0;
    int res = 0;
    for (auto c : s) {
        int x = c - '0';
        if (!trie[p][x]) return res;
        p = trie[p][x];
        res += ed[p];
    }
    res += exist[p] - ed[p];
    return res;
}
signed main()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s = "";
        int k; cin >> k;
        for (int j = 1; j <= k; j++) {
            int x; cin >> x;
            s += x + '0';
        }
        insert(s);
    }
    for (int i = 1; i <= m; i++) {
        string t = "";
        int k; cin >> k;
        for (int j = 1; j <= k; j++) {
            int x; cin >> x;
            t += x + '0';
        }
        cout << qry(t) << "\n";
    }
    return 0;
}

