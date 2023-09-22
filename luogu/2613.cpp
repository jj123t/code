/*************************************************************************
	> File Name: 2613.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Aug  2 11:47:52 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int t;
const int mod = 19260817;
long long read() {
    char c = getchar();
    long long t = 0;
    while (c < '0' or c > '9') c = getchar();
    while (c >= '0' and c <= '9') {
        t = (t * 10 + c - '0') % mod;
        c = getchar();
    }
    return t;
}
int extgcd(int &x, int &y, int a, int b) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = extgcd(y, x, b, a % b);
    y -= a / b * x;
    return d;
}
signed main()
{
    int a = read();
    int b = read();
    if (b == 0) {
        cout << "Angry!" ;
            return 0;
    }
    int x, y; extgcd(x, y, b, mod);
    x = (x + mod) % mod;
    int ans = (x * a + mod) % mod;
    cout << ans << "\n";
    return 0;
}

