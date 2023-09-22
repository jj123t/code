/*************************************************************************
	> File Name: 5514.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul 31 21:54:53 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long x; cin >> x;
        ans ^= x;
    }
    cout << ans << "\n";
    return 0;
}

