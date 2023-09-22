/*************************************************************************
	> File Name: 1777c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul 12 14:07:20 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<int> arr(n);
        vector<int> cnt(m + 1);
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        int ans = 1e9;
        int tmp = 0;
        for (int i = 0, j = 0; i < n; i++) {
            while (tmp < m and j < n) {
                for (int k = 1; k * k <= arr[j]; k++) {
                    if (arr[j] % k == 0) {
                        if (k > m) continue;
                        cnt[k]++;
                        if (cnt[k] == 1) tmp++;
                        if (arr[j] / k != k) {
                            if (arr[j] / k > m) continue;
                            cnt[arr[j] / k]++;
                            if (cnt[arr[j] / k] == 1) tmp++;
                        }
                    }
                }
                j++;
            }
            if (tmp == m) ans = min(ans, arr[j - 1] - arr[i]);
            for (int k = 1; k * k <= arr[i]; k++) {
                if (arr[i] % k == 0) {
                    if (k > m) continue;
                    cnt[k]--;
                    if (cnt[k] == 0) tmp--;
                    if (arr[i] / k != k) {
                        if (arr[i] / k > m) continue;
                        cnt[arr[i] / k]--;
                        if (cnt[arr[i] / k] == 0) tmp--;
                    }
                }
            }
        }
        if (ans == 1e9) cout << -1 << "\n";
        else cout << ans << "\n";
    }
    return 0;
}

