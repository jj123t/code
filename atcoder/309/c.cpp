/*************************************************************************
	> File Name: c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul  8 19:53:51 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n, k; cin >> n >> k;
    using P = pair<int, int> ;
    vector<P> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += arr[i].second;
    }
    int ans = 0;
    int t = 0;
    if (s <= k) {
        cout << 1 ;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        t += arr[i].second;
        if (s - t <= k) {
            ans = arr[i].first + 1;
            break;
        }
    }
    cout << ans;
    return 0;
}

