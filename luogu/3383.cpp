/*************************************************************************
	> File Name: 3383.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jun 10 01:55:44 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
bool used[200000000];
int p[2000000];
int cnt = 0;
void f(int n) {
    for (int i = 2; i <= n; i++) {
        if (!used[i]) p[++cnt] = i;
        for (int j = 1; j <= cnt && i * p[j] <= n; j++) {
            used[i * p[j]] = true;
            if (i % p[j] == 0) break;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, q; cin >> n >> q;
    f(n);
    while (q--) {
        int x; cin >> x;
        cout << p[x] << "\n";
    }
    return 0;
}

