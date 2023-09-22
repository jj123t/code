/*************************************************************************
	> File Name: 1809a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul 12 20:20:55 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        string s; cin >> s;
        map<int, int> mp;
        for (auto c : s) mp[c]++;
        if (mp.size() == 1) cout << -1 << "\n";
        else if (mp.size() == 4) cout << 4 << "\n";
        else if (mp.size() == 3) {
            cout << 4 << "\n";
        }
        else {
            if ((*mp.begin()).second == 2) {
                cout << 4 << "\n";
            }
            else {
                cout << 6 << "\n";
            }
        }
    }
    return 0;
}

