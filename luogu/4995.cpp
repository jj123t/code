/*************************************************************************
	> File Name: 4995.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Aug 14 20:18:20 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> res;
    int left = 0, right = n;
    for (int i = 0; i <= n; i++) {
        if (i & 1) {
            res.push_back(a[right--]);
        }
        else {
            res.push_back(a[left++]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (res[i] - res[i - 1]) * (res[i] - res[i - 1]);
    }
    cout << ans << "\n";
    return 0;
}

