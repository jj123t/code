/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed 12 Apr 2023 09:31:43 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
int dp[2010][2010];
int INF = 1e9 + 7;
signed main () {
    int n; cin >> n;
    using P = pair<int, int>;
    vector<P> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    for (int l = n - 1; l > -1; l--) {
        for (int r = l; r < n; r++) {
            int i = l + (n - 1 - r);
            if (l == r) {
                dp[l][r] = arr[i].first * abs(arr[i].second - l);
            }
            else {
                dp[l][r] = -INF;
                dp[l][r] = max(dp[l][r], dp[l + 1][r] + arr[i].first * abs(arr[i].second - l));
                dp[l][r] = max(dp[l][r], dp[l][r - 1] + arr[i].first * abs(arr[i].second - r));
            }
        }
    }
    cout << dp[0][n - 1];
    return 0;
}
