/*************************************************************************
	> File Name: 1868.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul 18 11:07:52 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    using P = pair<int, int>;
    vector<P> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i].second >> arr[i].first;
    sort(arr.begin() + 1, arr.end());
    vector<int> dp(n + 1);
    auto binary_s = [&](int l, int r, int x) -> int {
        while (l <= r) {
            int mid = l + r >> 1;
            if (arr[mid].first < x) l = mid + 1;
            else r = mid - 1;
        }
        return r;
    };
    for (int i = 1; i <= n; i++) {
        auto [r, l] = arr[i];
        int it = binary_s(0, i, l);
        dp[i] = max(dp[i - 1], dp[it] + (r - l + 1));
    }
    cout << dp[n] << "\n";
    return 0;
}

