/*************************************************************************
	> File Name: 1804a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul 12 22:23:09 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int a, b; cin >> a >> b;
        int d = abs(abs(a) - abs(b));
        if (d == 0) d = 1;
        cout << abs(a) + abs(b) + d - 1 << "\n";
    }
    return 0;
}

