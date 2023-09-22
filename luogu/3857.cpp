/*************************************************************************
	> File Name: 3857.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Aug 16 10:41:53 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            if (c == 'O') a[i] ^= (1ll << j);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 51; j >= 0; j--) {
            if (a[i] >> j & 1) {
                if (!b[j]) {
                    b[j] = a[i]; break;
                }
                else {
                    a[i] ^= b[j];
                }
            }
        }
    }
    return 0;
}

