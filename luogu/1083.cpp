/*************************************************************************
	> File Name: 1083.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jun 17 02:51:58 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<array<int, 3>> sig(m + 1);
    for (int i = 1; i <= m; i++) {
        int d, s, t; cin >> d >> s >> t;
        sig[i] = {d, s, t};
    }
    auto check = [&](int mid) {
        vector<int> tag(n + 2);
        for (int i = 1; i <= mid; i++) {
            tag[sig[i][1]] += sig[i][0];
            tag[sig[i][2] + 1] -= sig[i][0];
        }
        for (int i = 1; i <= n; i++) {
            tag[i] += tag[i - 1];
            if (tag[i] > arr[i]) {
                return false;
            }
        }
        return true;
    };
    if (check(m)) {
        cout << 0;
        return 0;
    }
    int left = 1, right = m;
    while (left <= right) {
        int mid = left + right >> 1;
        if (check(mid)) left = mid + 1;
        else right = mid - 1;
    }
    cout << -1 << "\n" << left << "\n";
    return 0;
}

