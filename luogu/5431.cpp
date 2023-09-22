/*************************************************************************
	> File Name: 5431.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jun 10 02:49:28 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
inline void read(long long &x)
{
    char c;
    x = 0;
    int fu = 1;
    c = getchar();
    while(c > 57 || c < 48)
    {
        if(c == 45)
        {
            fu = -1;
        }
        c = getchar();
    }
    while(c <= 57 && c >= 48)
    {
        x = (x << 3) + (x << 1) + c - 48;
        c = getchar();
    }
    x *= fu;
}
inline void fprint(long long x)
{
    if(x < 0)
    {
        putchar(45);
        x = -x;
    }
    if(x > 9)
    {
        fprint(x / 10);
    }
    putchar(x % 10 + 48);
}
int mypow(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1) res = (long long)res * a % p;
        a = (long long)a * a % p;
        b >>= 1;
    }
    return res;
}
int inv(int x, int p) {
    return mypow(x, p - 2, p) % p;
}
vector<long long> arr(5000100), pfx(5000100, 1), sufx(5000100, 1);
int main() {
    long long n, p, k; read(n); read(p); read(k);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1, j = n; i <= n, j >= 1; i++, j--) pfx[i] = pfx[i - 1] * arr[i] % p, sufx[j] = sufx[j + 1] * arr[j] % p;
    long long t = inv(pfx[n], p);
    long long ans = 0;
    for (int i = 1, res = k; i <= n; i++, res = res * k % p) {
        long long pre = pfx[i - 1];
        long long nxt = sufx[i + 1];
        long long tmp = pre * nxt % p;
        tmp = tmp * t % p;
        tmp = tmp * res % p;
        ans = (ans + tmp) % p;
    }
    fprint(ans % p);
    return 0;
}
