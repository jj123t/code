/*************************************************************************
	> File Name: 1783c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jun 29 16:54:16 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1050;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        using P = pair<int, int>;
        vector<P> arr(n + 1);
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            arr[i] = {x, i};
        }
        sort(arr.begin() + 1, arr.end());
        int t = 0;
        vector<int> res(n + 10, false);
        for (int i = 1; i <= n; i++) {
            auto [f, x] = arr[i];
            if (m >= f) {
                res[x] = true;
                m -= f;
                t++;
            }
            else {
                int j = i;
                while (j <= n && m + arr[i - 1].first >= arr[j].first) {
                    res[arr[j++].second] = true;
                }
                break;
            }
        }
        cout << n + 1 - t - res[t + 1] << "\n";
    }
    return 0;
}

