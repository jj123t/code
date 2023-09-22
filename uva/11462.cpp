/*************************************************************************
	> File Name: 11462.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Sep 16 22:27:31 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n; 
    while (cin >> n and n) {
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a.begin() + 1, a.end());
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " \n"[i == n];
        }
    }
    return 0;
}

