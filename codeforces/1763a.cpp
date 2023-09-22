/*************************************************************************
	> File Name: 1763a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jul  2 15:04:58 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(30);
        vector<int> brr(30);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            for (int j = 0; j < 30; j++) {
                if (x >> j & 1) arr[j]++;
                else brr[j]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < 30; i++) {
            if (arr[i] && brr[i]) {
                ans += (1 << i);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

