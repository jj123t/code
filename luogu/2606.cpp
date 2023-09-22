/*************************************************************************
	> File Name: 2606.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Aug  6 17:59:39 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n, m;
int siz[1000000];
int dp[1000000];
map<int, int> mp[1000000];
int C(int a, int b) {
    if (b == 0) return 1;
    if (a == 0) return 0;
    if (mp[a][b]) return mp[a][b];
    return mp[a][b] = C(a - 1, b - 1) + C(a - 1, b) % m;
}
int Lucas(int a, int b) {
    if (b == 0) return 1;
    return Lucas(a / m, b / m) * C(a % m, b % m) % m;
}
int dfs(int x) {
    if (x > n) return 1;
    if (dp[x]) return dp[x];
    siz[x] = 1;
    dp[x * 2] = dfs(x * 2) % m;
    dp[x * 2 + 1] = dfs(x * 2 + 1) % m;
    siz[x] += siz[x * 2] + siz[x * 2 + 1];
    return dp[x] = Lucas(siz[x] - 1, siz[x * 2]) * (dp[x * 2] * dp[x * 2 + 1] % m) % m;
}
signed main()
{
    cin >> n >> m;
    cout << dfs(1) % m;
    return 0;
}

