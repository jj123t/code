/*************************************************************************
	> File Name: 1759d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jun 27 06:10:02 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        int cp = n;
        int two = 0, five = 0;
        while (n % 2 == 0) {
            two++;
            n /= 2;
        }
        while (n % 5 == 0) {
            five++;
            n /= 5;
        }
        int cnt = 1;
        while (two < five && cnt * 2 <= k)  cnt *= 2, two++;
        while (two > five && cnt * 5 <= k)  cnt *= 5, five++;
        while (cnt * 10 <= k) {
            cnt *= 10;
        }
        int d = k / cnt;
        cout << cp * cnt * d << "\n";
    }
    return 0;
}

