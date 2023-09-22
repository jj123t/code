/*************************************************************************
	> File Name: p1067.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon May 29 00:49:22 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    for (auto &x : a) cin >> x;
    for (int i = 0; i < n + 1; i++) {
        if (a[i] == 0) continue;
        if (a[i] < 0) {
            cout << "-";
        }
        else {
            if (i > 0) cout << "+"; 
        }
        if (abs(a[i]) != 1) cout << abs(a[i]); 
        else if (n - i == 0) cout << "1";
        if (n - i == 1) cout << "x";
        else if (n - i == 0) continue;
        else cout << "x^" << (n - i);
    }
    return 0;
}

