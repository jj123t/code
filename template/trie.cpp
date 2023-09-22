#include<bits/stdc++.h>
using namespace std;
struct trie {
    int nex[100000][26], cnt;
    bool exist[100000];
    void insert(string s, int len) {
        int p = 0;
        for (int i = 0; i < len; i++) {
            int c = s[i] - 'a';
            if (!nex[p][c]) nex[p][c] = ++cnt; 
            p = nex[p][c];
        }
        exist[p] = 1;
    }
    bool find(string s, int len) {
        int p = 0;
        for (int i = 0; i < len; i++) {
            int c = s[i] - 'a';
            if (!nex[p][c]) return false; 
            p = nex[p][c];
        }
        return exist[p];
    }
};
int main()
{
    return 0;
}

