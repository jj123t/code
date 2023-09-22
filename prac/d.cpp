/*************************************************************************IN
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu May 11 01:46:57 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        if (n == 1) {
            cout << "2" << "\n";
            continue;
        }
        int left = 2, right = 1e10;
        auto f = [&](int mid) -> int {
            return mid * (mid - 1) / 2;
        };
        while (left <= right) { 
            int mid = (left + right) >> 1;
            if (f(mid) > n) right = mid - 1;
            else left = mid + 1;
        }
        cout << right + (n - f(right)) << '\n';
    }
    return 0;
}

