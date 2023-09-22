/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed May 17 04:02:41 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n;
vector<int> a(N, 0);
map<int, int> mp;
int dfs(int x, int idx) {
    if (idx == n - 1) return x / a[idx];
    if (mp[x]) return mp[x];
    if (x == 0) return 0;
    int ra = a[idx], rb = a[idx + 1];
    int r = x % rb / ra;
    int ans = dfs(x / rb * rb, idx + 1) + r;
    if (r) {
        ans = min(ans, dfs((x + rb - 1) / rb * rb, idx + 1) + (rb / ra - r));  
    }
    return mp[x] = ans;
}
signed main()
{
    int x; cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << dfs(x, 0);
    return 0;
}

