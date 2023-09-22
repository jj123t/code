/*************************************************************************
	> File Name: 3879.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jun 10 01:18:28 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int trie[500010][26];
bitset<1010> exist[500010];
int n, cnt;
int ans[500010];
void insert(string s, int id) {
    int p = 0;
    for (auto c : s) {
        int x = c - 'a';
        if (!trie[p][x]) trie[p][x] = ++cnt;
        p = trie[p][x];
    }
    exist[p][id] = true;
}
void qry(string s) {
    int p = 0;
    for (auto c : s) {
        int x = c - 'a';
        if (!trie[p][x]) {
            cout << "\n";
            return ;
        }
        p = trie[p][x];
    }
    int top = 0;
    for (int i = 1; i <= n; i++) {
        if (exist[p][i]) {
            ans[++top] = i;
        }
    }
    for (int i = 1; i <= top; i++) {
        if (i != top) {
            cout << ans[i] << " ";
        }
        else cout << ans[i];
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        for (int j = 1; j <= k; j++) {
            string s; cin >> s;
            insert(s, i);
        }
    }
    int m; cin >> m;
    for (int i = 1; i <= m; i++) {
        string s; cin >> s;
        qry(s);
    }
    return 0;
}
