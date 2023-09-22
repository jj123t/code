/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun 16 Apr 2023 04:54:24 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
signed main () {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (auto &a : arr) cin >> a;
    int left = 1, right = *max_element(arr.begin(), arr.end());
    while (left < right) {
        int mid = left + right >> 1;
        int res = 0;
        for (auto x : arr) {
            res += (x - 1) / mid;
        }
        if (res <= k) right = mid;
        else left = mid + 1;
    }
    cout << left;
    return 0;
}
