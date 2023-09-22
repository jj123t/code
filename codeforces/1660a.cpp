/*************************************************************************
	> File Name: 1660a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Sep  6 20:48:36 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int a, b; cin >> a >> b;
        if (a == 0) {
            cout << 1 << '\n';
        }
        else {
            cout << a + b * 2 + 1 << '\n';
        }
    }
    return 0;
}

