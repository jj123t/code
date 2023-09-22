/*************************************************************************
	> File Name: test.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed May 10 02:48:57 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
using P = pair<int, int>;
const int p = 998244253;
int n;
vector<int> tou[100100];
map<vector<int>, int> mp[100100];
bool check(vector<int> a) {
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) return false;
    }
    return true;
}
int dfs(int idx, vector<int>st) {
    if (idx == n) {
        return 1;
    }
    if (mp[idx][st]) return mp[idx][st];
    int ans = 0;
    for (auto x : tou[idx]) {
        if (x == st.back()) continue;
        st.push_back(x);
        ans = (ans + dfs(idx, st)) % p;
        st.pop_back();
    }
    mp[idx][st] = ans;
    return ans;
}
signed main()
{
    cin >> n;
    int m; cin >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            tou[i].push_back(x);
        }
    }
    cout << dfs(0, {});
    return 0;
}

