/*************************************************************************
	> File Name: 1766a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jun 28 00:11:50 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int ans = 0;
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 1000000; j *= 10) {
                if (j * i <= n) {
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

