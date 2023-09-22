/*************************************************************************
	> File Name: f.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul  3 20:10:08 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n, m; cin >> n >> m;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    using P = pair<int, int>;
    vector<P> arr(m);
    for (int i = 0; i < m; i++) cin >> arr[i].first;
    for (int i = 0; i < m; i++) cin >> arr[i].second;
    priority_queue<int> q;
    sort(c.begin(), c.end());
    sort(arr.begin(), arr.end());
    int idx = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (idx < m && arr[idx].first <= c[i]) {
            q.push(arr[idx].second);
            idx++;
        } 
        if (!q.empty()) {
            ans += c[i] - q.top();
            q.pop();
        }
        else {
            ans += c[i];
        }
    }
    cout << ans ;
    return 0;
}

