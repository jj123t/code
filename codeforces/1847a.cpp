/*************************************************************************
	> File Name: 1847a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul  6 22:04:58 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<int> res;
        for (int i = 1; i < n; i++) {
            res.push_back(abs(arr[i] - arr[i - 1]));
        }
        sort(res.begin(), res.end());
        reverse(res.begin(), res.end());
        int idx = 0;
        int ans = 0;
        for (int i = 0; i < res.size(); i++) {
            if (i < m - 1) ;
            else ans += res[i];
        }
        cout << ans << "\n";
    }
    return 0;
}

