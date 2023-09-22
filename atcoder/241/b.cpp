/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed May 31 01:14:00 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int n, m; cin >> n >> m;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    bool flag = true;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        if (mp[x]) {
            mp[x]--;
        }
        else {
            flag = false;
        }
    }
    cout << (flag ? "Yes\n" : "No\n");
    return 0;
}

