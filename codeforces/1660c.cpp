/*************************************************************************
	> File Name: 1660c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Sep  6 21:13:22 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        string s; cin >> s;
        int n = s.size();
        map<char, int> mp;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!mp[s[i - 1]]) mp[s[i - 1]]++;
            else {
                mp[s[i - 1]]--;
                for (auto [x, y] : mp) {
                    ans += y;
                }
                mp.clear();
            }
        }
        for (auto [x, y] : mp) ans += y;
        cout << ans << "\n";
    }
    return 0;
}

