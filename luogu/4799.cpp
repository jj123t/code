/*************************************************************************
	> File Name: 4799.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Sep  1 18:25:53 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n, m;
vector<int> arr(1e6);
vector<int> a, b;
void dfs(int l, int r, int t) {
    if (l == r) {
        a.push_back(t);
        return ;
    }
    dfs(l + 1, r, t + arr[l]);
    dfs(l + 1, r, t);
}
signed main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int mid = n >> 1;
    dfs(0, mid + 1, 0);
    b = a;
    a.clear();
    dfs(mid + 1, n, 0);
    int ans = 0;
    const long long INF = 1e18;
    a.push_back(INF);
    b.push_back(INF);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < (long long)a.size() - 1; i++) {
        int x = a[i];
        auto it = upper_bound(b.begin(), b.end(), m - x);
        ans += (long long) (it - b.begin());
    }
    cout << ans << "\n";
    return 0;
}

