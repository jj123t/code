/*************************************************************************
	> File Name: c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 15 19:55:31 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    map<string, int> mp;
    int ans = 0;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        string t = s;
        reverse(s.begin(), s.end());
        if (!mp[s] and !mp[t]) ans++;
        mp[s] = true;
        mp[t] = true;
    }
    cout << ans << "\n";
    return 0;
}

