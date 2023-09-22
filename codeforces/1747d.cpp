/*************************************************************************
	> File Name: 1747d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jun 24 21:44:29 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> xorp(n + 1, 0);
    vector<int> plusp(n + 1, 0);
    for (int i = 0; i < n; i++) {
        xorp[i + 1] = xorp[i] ^ arr[i];
        plusp[i + 1] = plusp[i] + arr[i];
    }
    map<int, vector<int>> odd, even;
    for (int i = 0; i <= n; i++) {
        if (i & 1) odd[xorp[i]].push_back(i);
        else even[xorp[i]].push_back(i);
    }
    while (q--) {
        int l, r; cin >> l >> r;
        if (plusp[r] - plusp[l - 1] == 0) {
            cout << 0 << "\n";
            continue;
        }
        if ((xorp[r] ^ xorp[l - 1]) != 0) {
            cout << -1 << "\n";
            continue;
        }
        if ((r - l + 1) & 1) {
            cout << 1 << "\n";
            continue;
        }
        if (arr[r - 1] == 0 || arr[l - 1] == 0) {
            cout << 1 << "\n";
            continue;
        }
        if (l % 2 == 0) {
            int x = xorp[l - 1];
            auto it = lower_bound(even[x].begin(), even[x].end(), l + 1);
            if (it != even[x].end() && (*it) < r) {
                cout << 2 << "\n";
            }
            else cout << -1 << "\n";
        }
        else {
            int x = xorp[l - 1];
            auto it = lower_bound(odd[x].begin(), odd[x].end(), l + 1);
            if (it != odd[x].end() && (*it) < r) {
                cout << 2 << '\n';
            }
            else cout << -1 << '\n';
        }
    }
    return 0;
}

