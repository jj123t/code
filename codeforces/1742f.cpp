/*************************************************************************
	> File Name: 1742f.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jun 23 04:51:28 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        map<char, int> mps, mpt;
        mps['a']++, mpt['a']++;
        int sza = 1, szb = 1;
        int q; cin >> q;
        while (q--) {
            int op; int k; string s; cin >> op >> k >> s;
            for (auto c : s) {
                if (op == 1) {
                    sza += k;
                    mps[c] += k;
                }
                else {
                    szb += k;
                    mpt[c] += k;
                }
            }
            bool flag = false;
            char st = 'a';
            while (mps[st] == 0) {
                st++;
            }
            for (int i = (st - 'a') + 1; i < 26; i++) {
                if (mpt[i + 'a']) {
                    flag = true;
                    break;
                }
            }
            if (sza == mps[st] && mpt[st] > sza) {
                flag = true;
            }
            cout << (flag ? "YES\n" : "NO\n");
        }
    }
    return 0;
}
