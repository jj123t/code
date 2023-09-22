/*************************************************************************
	> File Name: 1660b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Sep  6 20:52:44 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int bound;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) cin >> arr[i];
        int mx1 = 0, mx2 = 0;
        for (int i = 1; i <= n; i++) {
            if (arr[i] >= mx1) {
                mx2 = mx1;
                mx1 = arr[i];
            }
            else if (arr[i] > mx2) {
                mx2 = arr[i];
            }
        } 
        if (mx1 - mx2 <= 1) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}

