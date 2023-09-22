/*************************************************************************
	> File Name: 10810.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Sep 16 22:09:21 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e6;
int tree[N];
int n;
void add(int i, int x) {
    while (i <= n) {
        tree[i] += x;
        i += (i & -i);
    }
}
int qry(int i) {
    int res = 0;
    while (i) {
        res += tree[i];
        i -= (i & -i);
    }
    return res;
}
signed main()
{
    cin >> n;
    while (n != 0) {
        memset(tree, 0, sizeof tree);
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        set<int> st; map<int, int> mp; int cnt = 0;
        for (int i = 1; i <= n; i++) st.insert(a[i]);
        for (auto x : st) mp[x] = ++cnt;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int x = a[i];
            add(mp[x], 1);
            ans += i - qry(mp[x]);
        }
        cout << ans << "\n";
        cin >> n;
    }
    return 0;
}

