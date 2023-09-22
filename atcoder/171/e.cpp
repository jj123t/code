/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri 14 Apr 2023 06:47:58 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
signed main () {
    int n; cin >> n;
    vector<int> arr(n + 1, 0);
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        tmp ^= arr[i];
    }
    vector<int> ans(n + 1, 0);
    for (int i = 0; i < n; i++) {
        ans[i] = tmp ^ arr[i];
    }
    for (int i = 0; i < n; i++) cout << ans[i] << "\n";
    return 0;
}
