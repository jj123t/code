/*************************************************************************
	> File Name: 1808b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul 12 17:49:08 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<int> arr[m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x; cin >> x;
                arr[j].push_back(x);
            }
        }
        for (int i = 0; i < m; i++) {
            sort(arr[i].rbegin(), arr[i].rend());
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int w = n - 1, l = 0;
            for (int j = 0; j < n; j++) {
                ans += arr[i][j] * (w--) - arr[i][j] * (l++); 
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

