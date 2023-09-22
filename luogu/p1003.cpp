/*************************************************************************
	> File Name: p1003.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu May 18 19:28:05 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int n; cin >> n;
    vector<array<int, 4>> arr(n);
    for (int i = 0; i < n; i++) {
        int a, b, g, k; cin >> a >> b >> g >> k;
        arr[i] = {a, b, g, k};
    }
    int x, y; cin >> x >> y;
    int ans = -1;
    for (int i = 0; i < n; i++) {
        auto [a, b, g, k] = arr[i];
        if ((a <= x && x <= a + g) && (b <= y && y <= b + k)) {
            ans = i + 1;
        }
    }
    cout << ans;
    return 0;
}

