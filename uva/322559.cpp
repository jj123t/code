/*************************************************************************
	> File Name: 322559.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Sep 16 20:52:56 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin >> n) {
        int g; cin >> g;
        using P = pair<int, int>;
        vector<P> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
        sort(a.begin() + 1, a.end(), [&](P x, P y) {
             return x.second - x.first < y.second - y.first;
             });
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i].first > a[i].second) ans += 3;
            else if (a[i].first == a[i].second) {
                if (g) g--, ans += 3;
                else ans++;
            }
            else {
                if (g >= a[i].second - a[i].first + 1) g -= a[i].second - a[i].first + 1, ans += 3;
                else if (g == a[i].second - a[i].first) g -= a[i].second - a[i].first, ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

