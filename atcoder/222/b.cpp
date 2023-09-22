/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat May 13 18:39:20 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int n, k; cin >> n >> k;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x < k) ans++;
    }
    cout << ans;
    return 0;
}

