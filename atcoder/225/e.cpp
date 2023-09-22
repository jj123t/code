/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun May 14 20:47:58 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct point {
    ll x, y;
    point(ll xx = 0, ll yy = 0) {
        x = xx; y = yy;
    }
    bool operator < (const point a) const {
        return x * a.y - y * a.x > 0;
    }
    bool operator <= (const point a) const {
        return x * a.y - y * a.x >= 0;
    }
};
int main()
{
    int n; cin >> n;
    vector<pair<point, point>> a(n);
    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        a[i] = make_pair(point(x - 1, y), point(x, y - 1));
    }
    sort(a.begin(), a.end());
    point t;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (t <= a[i].second) {
            t = a[i].first;
            ans++;
        }
    }
    cout << ans;
    return 0;
}

