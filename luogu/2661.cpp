/*************************************************************************
	> File Name: 2661.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jun 17 06:07:30 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

int ans = 1e9;
vector<bool> thislop(N, false);
vector<bool> lastlop(N, false);
vector<int> pre(N, 0);
vector<int> e(N, 0);

void dfs(int idx, int cnt) {
    if (lastlop[idx]) return;
    if (thislop[idx]) ans = min(ans, cnt - pre[idx]);
    else {
        thislop[idx] = true;
        pre[idx] = cnt;
        dfs(e[idx], cnt + 1);
        lastlop[idx] = true;
    }
}
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> e[i];
    for (int i = 1; i <= n; i++) dfs(i, 0);
    cout << ans;
    return 0;
}
