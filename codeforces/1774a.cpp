/*************************************************************************
	> File Name: 1774a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul  4 11:30:20 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        int tmp = s[0] - '0';
        string ans = "";
        for (int i = 1; i < n; i++) {
            int x = s[i] - '0';
            if (abs(tmp - x) < abs(tmp)) {
                ans += "-";
                tmp -= x;
            }
            else {
                ans += "+";
                tmp += x;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

