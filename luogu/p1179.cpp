/*************************************************************************
	> File Name: p1179.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon May 29 23:16:55 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int l, r; cin >> l >> r;
    int ans = 0;
    for (int i = l; i <= r; i++) {
        int tmp = i;
        while (tmp) {
            if (tmp % 10 == 2) ans++;
            tmp /= 10;
        }
    }
    cout << ans;
    return 0;
}

