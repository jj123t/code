/*************************************************************************
	> File Name: 1787b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 14 23:07:07 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int ans = 0;
        int x = n;
        using P = pair<int, int> ;
        vector<P> arr;
        for (int i = 2; i * i <= x; i++) {
            int res = 0;
            if (x % i != 0) continue;
            while (x % i == 0) {
                res++;
                x /= i;
            }
            arr.push_back({res, i});
        }
        if (x > 1) arr.push_back({1, x});
        sort(arr.rbegin(), arr.rend());
        int t = arr[0].second;
        for (int i = 1; i < arr.size(); i++) {
            ans += (arr[i - 1].first - arr[i].first) * t;
            t *= arr[i].second;
        }
        ans += (arr.back().first) * t;
        cout << ans << "\n";
    }
    return 0;
}

