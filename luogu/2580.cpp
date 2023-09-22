/*************************************************************************
	> File Name: 2580.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 15 12:09:14 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int nxt[1000010][26], cnt = 0;
bool exist[1000010];
bool mp[1000010];
struct trie {
    void insert(string s, int len) {
        int p = 0;
        for (int i = 0; i < len; i++) {
            int c = s[i] - 'a';
            if (!nxt[p][c]) nxt[p][c] = ++cnt;
            p = nxt[p][c];
        }
        exist[p] = true;
    }
    int find(string s, int len) {
        int p = 0;
        for (int i = 0; i < len; i++) {
            int c = s[i] - 'a';
            if (!nxt[p][c]) return 0;
            p = nxt[p][c];
        }
        if (exist[p]) {
            if (!mp[p]) {
                mp[p] = true;
                return 1;
            }
            else return 2;
        }
        else {
            return 0;
        }
    }
}trie;
int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        trie.insert(s, s.size());
    }
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        int op = trie.find(s, s.size());
        if (op == 0) cout << "WRONG\n";
        else if (op == 1) cout << "OK\n";
        else cout << "REPEAT\n";
    }
    return 0;
}

