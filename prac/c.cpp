/*************************************************************************
	> File Name: c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu May 11 01:12:45 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main() 
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) cin >> arr[i];
        vector<int> brr(n + 1);
        auto c = arr;
        int j = n;
        for (int i = 1; i <= n; i++) {
            while (arr[j] < i) j--;
            brr[i] = j;
        }
        if (arr == brr) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
