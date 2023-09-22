/*************************************************************************
	> File Name: 1495.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Aug  3 09:25:15 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int __int128 
const int N = 1e5 + 10;
int a[N], m[N];
int extgcd(int &x, int &y, int a, int b) {
    if (!b) { x = 1, y = 0; return a; }
    int d = extgcd(y, x, b, a % b);
    y -= a / b * x;
    return d;
}
int rgcd(int a, int b) {
    if (!b) return a;
    return rgcd(b, a % b);
}
int n;
inline int rd(){
    int io=0;char in=getchar();
    while(in<'0'||in>'9')in=getchar();
    while(in>='0'&&in<='9')io=(io<<3)+(io<<1)+(in^'0'),in=getchar();
    return io;
}
void print(int x) {
    if (x) {
        print(x / 10); 
        cout << char(x % 10 + '0');
    }
}
int extcrt() {
    // x = a1 % m1 -> q1 * m1 + a1 = x
    // x = a2 % m2 -> q2 * m2 + a2 = x
    // q1 * m1 - q2 * m2 = a2 - a1
    int A = a[1], M = m[1]; 
    for (int i = 2; i <= n; i++) {
        a[i] %= m[i];
        int d = rgcd(M, m[i]);
        int rlc = M / d * m[i];
        if ((a[i] - A) % d != 0) return -1;
        int t1, t2; extgcd(t1, t2, M / d, m[i] / d);
        int k1 = t1 * (a[i] - A) / d;
        A = (((A % rlc) + (k1 % rlc) * (M % rlc) % rlc) + rlc) % rlc;
        M = rlc;
    }
    return A;
}

signed main()
{
    n = rd();
    for (int i = 1; i <= n; i++) {
        m[i] = rd();
        a[i] = rd();
    }
    int t = extcrt();
    if (t == 0) cout << "0";
    else print(t);
    return 0;
}

