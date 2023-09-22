/*************************************************************************
	> File Name: 1804b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul 12 22:37:11 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, k, d, w; cin >> n >> k >> d >> w;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            q.push(x);
        }
        int ans = 0;
        while (!q.empty()) {
            ans++;
            int ti = q.top() + w;
            int has = k;
            while (!q.empty() and q.top() <= ti + d and has > 0) {
                has--;
                q.pop();
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

