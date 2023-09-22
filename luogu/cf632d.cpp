/*************************************************************************
	> File Name: cf632d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Aug  3 15:30:49 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    map<int, int> mp;
    int x = arr[0];
    bool flag = false;
    int mi = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
        mi = min(mi, arr[i]);
        if (lcm(arr[i], x) >= m) flag = true;
        else x = lcm(arr[i], x);
    }

    if (mi > m) {
        cout << 1 << " " << 0 << "\n";
        return 0;
    }
    if (flag) x = m;

    int mx = 0, idx = 0;

    vector<int> cnt(x + 1);
    for (auto [a, b] : mp) {
        int t = a;
        while (t <= x) {
            cnt[t] += b;
            t += a;
        }
    }

    for (int i = 1; i <= x; i++) {
        if (cnt[i] > mx) {
            mx = cnt[i];
            idx = i;
        }
    }

    cout << idx << " " << mx << "\n";
    for (int i = 0; i < n; i++) {
        if (gcd(idx, arr[i]) == arr[i]) {
            cout << i + 1 << " ";
        }
    }

    return 0;
}

