/*************************************************************************
	> File Name: c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 29 20:12:56 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n, m; cin >> n >> m;
    vector<int> sell(n);
    vector<int> buy(m);
    for (int i = 0; i < n; i++) cin >> sell[i];
    for (int i = 0; i < m; i++) cin >> buy[i];
    int left = 0, right = 1e9;
    auto check = [&](int mid) -> bool {
        int a = 0;
        for (int i = 0; i < n; i++) {
            if (sell[i] <= mid) a++;
        }
        int b = 0;
        for (int i = 0; i < m; i++) {
            if (buy[i] >= mid) b++;
        }
        return a >= b;
    };
    while (left <= right) {
        int mid = left + right >> 1;
        if (check(mid)) right = mid - 1;
        else left = mid + 1;
    }
    cout << left << "\n";
    return 0;
}

