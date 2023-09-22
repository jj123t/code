/*************************************************************************
	> File Name: 11858.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Sep 16 21:08:15 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
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
int main()
{
    while (cin >> n) {
        int ans = 0;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) cin >> arr[i];
        set<int> st; map<int, int> mp;
        for (int i = 1; i <= n; i++) st.insert(arr[i]);
        int cnt = 0;
        for (auto x : st) mp[x] = ++cnt;
        memset(tree, 0, sizeof tree);
        for (int i = 1; i <= n; i++) {
            int x = mp[arr[i]];
            ans += i - 1 - qry(mp[x]);
            add(mp[x], 1);
        }
        cout << ans << "\n";
    }
    return 0;
}

