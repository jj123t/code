/*************************************************************************
	> File Name: 1868b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Sep 10 21:57:07 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        int n, k, s, t; cin >> n >> k >> s >> t;
        using P = pair<int, int>;
        vector<P> arr(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i].first >> arr[i].second;
        }
        set<int> sta, stb;
        auto fcost = [&](int a, int b) {
            if (a <= k and b <= k) return 0ll;
            else {
                int da = (long long )abs(arr[a].first - arr[b].first);
                int db = (long long )abs(arr[a].second - arr[b].second);
                return da + db;
            }
        };
        int ans = fcost(s, t);
        for (int i = 1; i <= k; i++) sta.insert(fcost(s, i)), stb.insert(fcost(t, i));
        if (!sta.empty()) 
        ans = min(ans, (long long)((*sta.begin()) + (*stb.begin())));
        cout << ans << '\n';
    }
    return 0;
}

