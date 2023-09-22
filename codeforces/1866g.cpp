/*************************************************************************
	> File Name: 1866g.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Sep  4 20:42:03 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
using P = pair<int, int>;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 1), D(n + 1);
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n; i++) cin >> D[i];

    vector<P> res[n + 1];
    for (int i = 1; i <= n; i++) {
        int l = max(i - D[i], 1);
        int r = min(i + D[i], n);
        if (A[i] == 0) continue;
        res[l].push_back({r, A[i]});
    }

    auto check = [&](int mid) -> bool {
        priority_queue<P, vector<P>, greater<P>> q;
        for (int i = 1; i <= n; i++) {
            for (auto [r, w] : res[i]) {
                if (w) q.push({r, w});
            }
            int tmp = mid;
            while (tmp > 0 and !q.empty()) {
                auto [r, w] = q.top(); q.pop();
                if (r < i) return false;
                int f = min(tmp, w);
                w -= f;
                tmp -= f;
                if (w) {
                    q.push({r, w});
                }
            }
        }
        if (!q.empty()) return false;
        return true;
    };
    int l = 0, r = 1e9;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << l;
    return 0;
}
