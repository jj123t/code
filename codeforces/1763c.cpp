/*************************************************************************
	> File Name: 1763c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jul  2 15:30:20 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n); 
        for (int i = 0; i < n; i++)  cin >> arr[i];
        if (n == 2) {
            cout << max(arr[0] + arr[1], 2 * abs(arr[0] - arr[1])) << '\n';
        }
        else if (n == 3) {
            int x = *max_element(arr.begin(), arr.end());
            if (arr[0] == x or arr[2] == x) {
                cout << 3 * x << '\n';
            }
            else {
                int a = arr[0] + arr[1] + arr[2];
                auto xa = arr; xa[0] = xa[1] = xa[1] - xa[0];
                auto xb = arr; xb[2] = xb[1] = xb[1] - xb[2];
                cout << max({a, *max_element(xa.begin(), xa.end()) * 3 , *max_element(xb.begin(), xb.end()) * 3}) << '\n';
            }
        }
        else {
            cout << n * (*max_element(arr.begin(), arr.end())) << '\n';
        }
    }
    return 0;
}

