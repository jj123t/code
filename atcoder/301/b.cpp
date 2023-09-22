/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun May 14 03:53:15 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int n; cin >> n;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    vector<int> ans;
    for (int i = 0; i < n - 1; i++) {
        int x = A[i];
        int y = A[i + 1];
        if (x > y) {
            while (x > y) {
                ans.push_back(x--);
            }
        }
        else {
            while (x < y) {
                ans.push_back(x++);
            }
        }
        if (i == n - 2) ans.push_back(y);
    }
    for (auto c : ans) cout << c << " ";
    return 0;
}

