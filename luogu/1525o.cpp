/*************************************************************************
	> File Name: 1525o.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jul 23 09:05:43 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e6;
vector<int> e[N];
vector<array<int, 3>> arr(N);
vector<int> col(N);
int n, m;
map<int, int> mp;
bool dfs(int u, int c) {
    mp[u] = true;
    col[u] = c;
    for (auto v : e[u]) {
        if (col[v] == c) return false; 
        if (!col[v] and !dfs(v, -c)) return false;
    }
    return true;
}
bool check(int mid) {
    for (int i = 0; i <= n; i++) e[i].clear();
    fill(col.begin(), col.begin() + n + 1, 0);
    int u = -1;
    set<int> st;
    for (int i = 0; i < m; i++) {
        auto [c, a, b] = arr[i];
        if (c >= mid) {
            st.insert(a);
            st.insert(b);
            e[a].push_back(b);
            e[b].push_back(a);
        }
    }
    mp.clear();
    for (auto u : st) {
        if (!mp[u]) {
            if (!dfs(u, 1)) return false;
        }
        else {
            continue;
        }
    }
    return true;
}
signed main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> arr[i][1] >> arr[i][2] >> arr[i][0];
    sort(arr.begin(), arr.begin() + m);
    int left = 0, right = 1e9 + 1;
    while (left <= right) {
        int mid = left + right >> 1ll;
        if (check(mid)) right = mid - 1;
        else left = mid + 1;
    }
    if (right < 0) cout << 0 << "\n";
    else cout << right << "\n";
    return 0;
}

