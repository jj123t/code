/*************************************************************************
	> File Name: 3092.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 22 22:17:49 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int k, n; cin >> k >> n;
    vector<int> w(k), dp((1 << k) + 1), arr(n + 2);
    int sum = 0;
    for (int i = 0; i < k; i++) { cin >> w[i]; sum += w[i]; }
    for (int i = 1; i <= n; i++) { cin >> arr[i]; arr[i] += arr[i - 1]; }
    arr[n + 1] = 1e17;
    auto f = [&](int x, int st) {
        int left = st, right = n, mid;
        while (left <= right) {
            int mid = left + right >> 1;
            if (arr[mid] - arr[st] == x) return mid;
            else if (arr[mid] - arr[st] < x) left = mid + 1;
            else right = mid - 1;
        }
        return right;
    };
    for (int i = 0; i < (1 << k); i++) {
        for (int j = 0; j < k; j++) {
            if (i >> j & 1) {
                int t = (i ^ (1 << j));
                int res = f(w[j], dp[t]);
                if (res > dp[i]) {
                    dp[i] = res; 
                }
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < (1 << k); i++) {
        if (dp[i] >= n) {
            int res = 0;
            for (int j = 0; j < k; j++) {
                if (i >> j & 1)
                    res += w[j];
            }
            ans = max(ans, sum - res);
        }
    }
    cout << ans << "\n";
    return 0;
}

