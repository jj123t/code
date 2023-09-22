/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed May 31 04:59:10 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define int long long 
const int N = 1e6 + 10;
vector<int> s(N);
vector<int> vis(N, -1);
signed main()
{
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    int idx = 0, res = 0;
    vis[0] = 0;
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + arr[s[i] % n];
        if (vis[s[i + 1] % n] != -1) {
            idx = i + 1;
            res = vis[s[i + 1] % n];
            break;
        }
        vis[s[i + 1] % n] = i + 1;
    }
    if (k <= res) {
        cout << s[k];
        return 0;
    }
    int sfx = (k - res - 1) / (idx - res) * (s[idx] - s[res]);
    int pre = s[res + (k - res - 1) % (idx - res) + 1];
    cout << sfx + pre;
    return 0;
}

