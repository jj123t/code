/*************************************************************************
	> File Name: 3522.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Aug  6 19:38:18 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    using P = pair<int, int>;
    vector<P> arr(n + 1); 
    for (int i = 1; i <= n; i++) cin >> arr[i].first >> arr[i].second;
    int j = 1, ans = 0;
    deque<P> q1, q2;
    for (int i = 1; i <= n; i++) {
        while (!q1.empty() and q1.front().first < i) q1.pop_front();
        while (!q2.empty() and q2.front().first < i) q2.pop_front();
        j = max(j, i);
        if (q1.empty() or q2.empty()) {
            q1.push_back({i, arr[i].first});
            q2.push_back({i, arr[i].second});
            j = max(i, j);
            ans = max(ans, 1);
            j = i + 1;
        }
        while (j <= n) {
            int mi = q1.front().second;
            int mx = q2.front().second;
            auto [a, b] = arr[j];
            if (a >= mx) {
                while (!q1.empty()) q1.pop_back();
                while (!q2.empty()) q2.pop_back();
                q1.push_back({j, a}); q2.push_back({j, b});
                ans = max(ans, j - i + 1);
                j++;
                continue;
            }
            int resa = max(mi, a);
            int resb = min(mx, b);
            if (resa <= resb) {
                ans = max(ans, j - i + 1);
                while (!q1.empty() and q1.back().second <= a) q1.pop_back();
                q1.push_back({j, a});
                while (!q2.empty() and q2.back().second >= b) q2.pop_back();
                q2.push_back({j, b});
                j++;
            }
            else break;
        }
    }
    cout << ans << "\n";
    return 0;
}

