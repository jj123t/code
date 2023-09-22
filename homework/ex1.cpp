/*************************************************************************
	> File Name: ex1.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue May 30 18:08:13 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

bool check(vector<int> res) {

    bool left[50];
    bool right[50];
    bool vis[50];
    memset(left, 0, sizeof(left));
    memset(right, 0, sizeof(right));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < 8; i++) {
        int x = i + res[i];
        int y = i - res[i] + 8; 
        if (vis[res[i]]) return false;
        vis[res[i]] = true;
        if (left[x] || right[y]) return false;
        left[x] = true, right[y] = true;
    }
    return true;
}
void print(vector<int> res) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (j == res[i]) cout << "*";
            else cout << ".";
        }
        cout << "\n";
    }
    cout << "\n";
}
int ans = 0;
void dfs(int idx, vector<int> res) {
    if (idx == 8) {
        if (check(res)) {
            print(res);
            ans++;
        }
        return ;
    }
    for (int i = 0; i < 8; i++) {
        res[idx] = i;
        dfs(idx + 1, res);
    } 
}
int main()
{
    vector<int> res(8);
    dfs(0, res);
    cout << ans;
    return 0;
}

