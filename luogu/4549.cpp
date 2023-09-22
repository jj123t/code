/*************************************************************************
	> File Name: 4549.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jun 10 01:44:29 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    int x; cin >> x;
    for (int i = 0; i < n; i++) {
        int r; cin >> r;
        if (r < 0) r *= -1;
        x = gcd(x, r);
    }
    cout << x;
    return 0;
}

