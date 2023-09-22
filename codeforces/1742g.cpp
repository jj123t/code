/*************************************************************************
	> File Name: 1742g.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jun 24 01:26:02 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr[31];
        int mx = 0;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            mp[x]++;
            mx = max(mx, x);
            int t = x;
            for (int j = 0; j < 30; j++) {
                if (t >> j & 1) {
                    arr[j].push_back(x);
                }
            }
        }
        vector<int> brr; brr.push_back(mx);
        mp[mx]--;
        int tmp = mx;
        while (true) {
            bool flag = false;
            for (int j = 30; j > -1; j--) {
                if ((tmp >> j & 1) == 0 && arr[j].size() != 0) {
                    int res = -1;
                    for (auto x : arr[j]) {
                        if (res == -1 || (x | tmp) > (res | tmp)) {
                            res = x;
                        }
                    }
                    mp[res]--;
                    brr.push_back(res);
                    tmp |= res;
                    flag = true;
                    break;
                }
            }
            if (!flag) break;
        }
        for (auto x : mp) {
            for (int i = 0; i < x.second; i++) {
                brr.push_back(x.first);
            }
        }
        for (auto x : brr) cout << x << " ";
        cout << '\n';
    }
    return 0;
}

