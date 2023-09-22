/*************************************************************************
	> File Name: cf61e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Sep 19 12:33:32 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e6 + 10;
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
    vector<int> num(n + 1), a(n + 1), b(n + 1);
    set<int> st; map<int, int> mp; int cnt = 0; 
    for (int i = 1; i <= n; i++) { cin >> num[i]; st.insert(num[i]); }
    for (auto x : st) mp[x] = ++cnt;
    for (int i = 1; i <= n; i++) {
        int x = mp[num[i]];
        a[i] = i - qry(x) - 1;
        add(x, 1);
    }
    memset(tree, 0, sizeof tree);
    for (int i = n; i >= 1; i--) {
        int x = mp[num[i]];
        b[i] = qry(x - 1);
        add(x, 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += a[i] * b[i];
    cout << ans << "\n";
    return 0;
}

