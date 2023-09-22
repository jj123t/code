/*************************************************************************
	> File Name: 1873b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Sep 21 22:38:48 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        int mx = 1e9;
        for (int i = 1; i <= n; i++) mx = min(mx, a[i]);
        int sum = 1;
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            if (!a[i]) {
                if (flag) {
                    sum *= a[i];
                }
                else {
                    flag = true;
                }
            }
            else {
                sum *= a[i];
            }
        }
        if (mx == 0) {
            sum *= (mx + 1);
        }
        else {
            sum /= mx;
            sum *= (mx + 1);
        }
        cout << sum << "\n";
    }
    return 0;
}

