/*************************************************************************
	> File Name: max_xor.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 15 12:48:52 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
struct trie {
    int nxt[100010][2], cnt = 0;
    int exist[100010];
    void insert(int val) {
        int p = 0;
        for (int i = 30; i > -1; i--) {
            int x = (val >> i & 1);
            if (!nxt[p][x]) nxt[p][x] = ++cnt; 
            p = nxt[p][x];
        }
        exist[p] = val;
    }
    int find(int val) {
        int p = 0;
        for (int i = 30; i > -1; i--) {
            int x = (val >> i & 1);
            if (!nxt[p][x ^ 1]) p = nxt[p][x];
            else p = nxt[p][x ^ 1];
        }
        return exist[p] ^ val;
    }
}
int main()
{
    for (int i = 0; i < n; i++) {

    }
    return 0;
}

