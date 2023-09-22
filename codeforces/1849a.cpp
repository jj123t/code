/*************************************************************************
	> File Name: 1849a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul 27 22:24:10 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int a, b, c; cin >> a >> b >> c;
        if (a - 1 <= b + c) cout << a + a - 1 << "\n";
        else {
            cout << (b + c) + (b + c) + 1 << "\n";
        }
    }
    return 0;
}

