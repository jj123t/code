/*************************************************************************
	> File Name: 1305.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul 26 22:04:07 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
struct node {
    char val;
    char left, right;
};
vector<node> mp(27);
void dfs(node root) {
    cout << root.val;
    if (root.left != '*') dfs(mp[root.left - 'a']);
    if (root.right != '*') dfs(mp[root.right - 'a']);
}
int main()
{
    int n; cin >> n;
    char root;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        if (i == 1) root = s[0];
        mp[s[0] - 'a'] = {s[0], s[1], s[2]};
    }
    dfs(mp[root - 'a']);
    return 0;
}

