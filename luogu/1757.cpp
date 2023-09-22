/*************************************************************************
	> File Name: 1757.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul 19 13:24:16 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int w, n; cin >> w >> n;
    using P = pair<int, int>;
    vector<P> arr[n + 1];
    for (int i = 1; i <= n; i++) {
        int a, b, c; cin >> a >> b >> c;
        arr[c].push_back(P(a, b));
    }
    vector<int> dp(w + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = w; j >= 0; j--) {
            for (auto [a, b] : arr[i]) {
                if (j - a >= 0) {
                    dp[j] = max(dp[j], dp[j - a] + b);
                }
            }
        }
    }
    cout << dp[w];
    return 0;
}

