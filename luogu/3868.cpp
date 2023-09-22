/*************************************************************************
	> File Name: 3868.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Aug  2 14:33:39 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int __int128 
const int N = 100010;
int a[N], m[N];
int n;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return x*f;
}
void print(int x) {
    if (x) {
        print(x / 10);
        cout << char(x % 10 + '0') ;
    }
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
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int extcrt() {
    int A = a[1], M = m[1];
    for (int i = 2; i <= n; i++) {
        int d = gcd(M, m[i]);
        int rlc = M / d * m[i];
        if ((a[i] - A) % d != 0) return -1;
        int t1, t2; extgcd(t1, t2, M / d, m[i] / d);
        int k1 = t1 * (a[i] - A) / d % rlc;
        k1 = ((k1 % rlc) + rlc) % rlc;
        A = ((A + k1 * M % rlc) + rlc) % rlc;
        M = rlc;
    }
    return A;
}
signed main()
{
    n = read();
    vector<int> arr(n + 1), brr(n + 1);
    for (int i = 1; i <= n; i++) arr[i] = read();
    for (int i = 1; i <= n; i++) brr[i] = read();
    for (int i = 1; i <= n; i++) {
        a[i] = ((arr[i] % brr[i]) + brr[i]) % brr[i];
        m[i] = brr[i];
    }
    int d = extcrt();
    if (d == 0) cout << 0 ;
    print(d);
    return 0;
}

