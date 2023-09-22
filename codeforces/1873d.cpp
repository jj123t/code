/*************************************************************************
	> File Name: 1873d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Sep 21 22:53:05 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int i;
        int ans = 0;
        for (i = 0; i < s.size(); ) {
            if (s[i] == 'B') {
                ans++;
                i += k;
            }
            else {
                i++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

