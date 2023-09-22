/*************************************************************************
	> File Name: 1082.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Aug  2 11:45:23 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int extgcd(int &x, int &y, int a, int b) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int d = extgcd(y, x, b, a % b);
    y -= a / b * x;
    return d;
}
signed main()
{
    int a, b; cin >> a >> b;
    int x, y; extgcd(x, y, a, b);
    cout << (x + b) % b << "\n";
    return 0;
}

