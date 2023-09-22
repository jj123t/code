/*************************************************************************
	> File Name: 3067.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Sep  2 14:52:05 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
map<int, vector<int>> res;
vector<int> vis((1 << 21)), arr(21);
int n; 
void dfs1(int idx, int s, int t) {
    if (idx > n / 2) {
        res[s].push_back(t);
        return ;
    }
    dfs1(idx + 1, s, t);
    dfs1(idx + 1, s + arr[idx], t | (1 << (idx - 1)));
    dfs1(idx + 1, s - arr[idx], t | (1 << (idx - 1)));
}
void dfs2(int idx, int s, int t) {
    if (idx > n) {
        if (!res.count(s)) return ;
        int r = res[s].size();
        for (int i = 0; i < r; i++) {
            vis[t | res[s][i]] = true;
        }
        return ;
    }
    dfs2(idx + 1, s, t);
    dfs2(idx + 1, s + arr[idx], t | (1 << (idx - 1)));
    dfs2(idx + 1, s - arr[idx], t | (1 << (idx - 1)));
}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    dfs1(1, 0, 0);
    dfs2(n / 2 + 1, 0, 0);
    int ans = 0;
    for (int i = 1; i < (1 << n); i++) {
        ans += vis[i];
    }
    cout << ans << "\n";
    return 0;
}

