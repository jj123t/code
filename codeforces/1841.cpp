/*************************************************************************
	> File Name: 1841.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jun 21 21:57:38 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (auto &x : arr) cin >> x;
        int now = arr[0], last = arr[0];
        bool flag = false;
        string ans = "1";
        for (int i = 1; i < n; i++) {
            if (!flag) {
                if (arr[i] >= last) {
                    last = arr[i];
                    ans += "1";
                }
                else {
                    if (arr[i] <= now) {
                        flag = true;
                        last = arr[i];
                        ans += "1";
                    }
                    else {
                        ans += "0";
                    }
                }
            }
            else {
                if (arr[i] >= last && arr[i] <= now) {
                    last = arr[i];
                    ans += "1";
                }
                else {
                    ans += "0";
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

