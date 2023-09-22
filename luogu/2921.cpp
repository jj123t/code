/*************************************************************************
	> File Name: 2921.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jun 18 21:03:50 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
const int N = 2e5 + 10;
vector<int> nxt(N);
vector<int> pre(N);
vector<int> lastlop(N);
vector<int> thislop(N);
vector<int> ans(N);
stack<int> st;
void dfs(int u, int cnt) {
    if (lastlop[u]) {
        int cnt = ans[u];
        while (!st.empty()) {
            ans[st.top()] = ++cnt;
            st.pop();
        }
        return ;
    }
    if (thislop[u]) {
        int x = cnt - pre[u];
        while (!st.empty() && st.top() != u) {
            ans[st.top()] = x;
            st.pop();
        }
        while (!st.empty()) {
            ans[st.top()] = x++;
            st.pop();
        }
    }
    else {
        pre[u] = cnt;
        st.push(u);
        thislop[u] = true;
        dfs(nxt[u], cnt + 1);
        lastlop[u] = true;
    }
}
int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> nxt[i];
    for (int i = 1; i <= n; i++) dfs(i, 0);
    for (int i = 1; i <= n; i++) cout << ans[i] << "\n";
    return 0;
}

