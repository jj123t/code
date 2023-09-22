/*************************************************************************
	> File Name: 1841c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jun 21 22:10:18 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define int long long 
int pw(char c) {
    return (long long)(pow(10, (long long)(c - 'A')));
}
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        string s; cin >> s;
        int n = s.size();
        using P = pair<int, int>;
        vector<int> res(n + 1, 0);
        map<int, P> mp;
        vector<vector<int>> pfx(n + 1, vector<int>(5, 0));
        vector<vector<int>> pff(n + 1, vector<int>(5, 0));
        vector<bool> has(n + 1, false);
        for (int i = n - 1; i > -1; i--) {
            int x = s[i] - 'A';
            mp[x].first++, mp[x].second = i;
            int t = 0;
            int idx = 0;
            for (int j = x + 1; j <= 4; j++) {
                t += mp[j].first;
                if (mp[j].first == 1) idx = mp[j].second;
            }
            if (t == 1) {
                pfx[idx][x] += pw(s[i]);
            }
            else if (t == 0) {
                pff[i + 1][x] += pw(s[i]);
            }

            if (t >= 1) res[i] = res[i + 1] - pw(s[i]), has[i] = true;
            else res[i] = res[i + 1] + pw(s[i]);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 4; j++) {
                pfx[i][j] += pff[i][j];
                pff[i + 1][j] += pff[i][j];
            }
        }
        /*
        for (int i = 0; i < n; i++) {
            cout << i << "  for --- ";
            for (int j = 0; j <= 4; j++) {
                cout << pfx[i][j] << " ";
            }
            cout << "\n";
        }
        */
        int ans = res[0];
        for (int i = 0; i < n; i++) {
            int x = s[i] - 'A';
            for (int j = 0; j <= 4; j++) {
                if (x > j) {
                    int yr = 0;
                    for (int k = j; k < x; k++) {
                        yr += pfx[i][k];
                    } 
                    /*
                    cout << "r1 -- ";
                    cout << yr << "\n";
                    */
                    ans = max(ans, res[0] + (has[i] ? 1 : -1) * pw(s[i]) + pw(char('A' + j)) + 2 * yr);
                }
                else if (x < j) {
                    int yr = 0;
                    for (int k = x; k < j; k++) {
                        yr += pfx[i][k];
                    }
                    /*
                    cout << "r2 -- ";
                    cout << yr << "\n";
                    */
                    ans = max(ans, res[0] + (has[i] ? 1 : -1) * pw(s[i]) + pw(char('A' + j)) - 2 * yr);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

