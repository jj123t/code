/*************************************************************************
	> File Name: 3861.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Aug  3 11:45:01 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        map<int, int> mp;
        int ans = 0;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                mp[i]++;
                mp[n / i]++;
                ans += mp[i] * mp[n / i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

