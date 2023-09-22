/*************************************************************************
	> File Name: 5539.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Aug  1 10:27:44 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int __int128
const int N = 1e5 + 10;
int n;
int a[N], m[N];
int extgcd(int &x, int &y, int a, int b) {
    if (!b) {  // a * x + b * y == gcd(a, b);
        x = 1, y = 0;
        return a;
    }
    int d = extgcd(y, x, b, a % b);
    y -= a / b * x;
    return d;
}
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int extcrt() {
    int M = m[1], A = a[1];
    int x;
    for (int i = 2; i <= n; i++) {
        int d = gcd(M, m[i]);
        int rlc = M * m[i] / d;
        if ((a[i] - A) % d != 0) return -1;
        int t1, t2;
        extgcd(t1, t2, M / d, m[i] / d);
        int k1 = (a[i] - A) * t1 / d;
        int x0 = (((A + k1 * M % rlc) % rlc) + rlc) % rlc;
        A = x0, M = rlc;
    }
    return A;
}
void print(int x) {
    if (x) {
        print(x / 10);
        cout << char(x % 10 + '0');
    }
    else return;
}
int read() {
    char c = getchar();
    int x = 0;
    while (c < 48) c = getchar();
    while (c > 47) x = (x * 10) + (c ^ 48), c = getchar();
    return x;
}
signed main()
{
    n = read();
    for (int i = 1; i <= n; i++) {
        m[i] = read(); a[i] = read();
    }
    print(extcrt());
    return 0;
}

