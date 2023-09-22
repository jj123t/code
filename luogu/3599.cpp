/*************************************************************************
	> File Name: 3599.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Sep 13 20:24:03 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int mypow(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
int inv(int x, int p) {
    return mypow(x, p - 2, p);
}
signed main()
{
    int type, tt; cin >> type >> tt;
    vector<int> isprime(1e6 + 10, true);
    for (int i = 2; i <= 1e6; i++) {
        for (int j = 2 * i; j <= 1e6; j += i) {
            isprime[j] = false;
        }
    }
    while (tt--) {
        if (type == 1) {
            int n; cin >> n;
            if ((n & 1) and (n ^ 1)) {
                cout << 0 << "\n";
            }
            else {
                cout << 2 << " ";
                for (int i = 1; i <= n; i++) {
                    if (i & 1) {
                        cout << n + 1 - i << " ";
                    }
                    else {
                        cout << i - 1 << " ";
                    }
                }
                cout << "\n";
            }
        }
        else {
            int n; cin >> n;
            if (n == 1) { cout << "0\n"; continue; } 
            if (n == 2) { cout << "2 1 2\n"; continue; }
            if (n == 4) { cout << "2 1 3 2 4\n"; continue; }
            if (isprime[n]) {
                cout << 2 << " ";
                int tmp = 1;
                for (int i = 1, s = 1; i <= n - 1; i++) {
                    cout << tmp << " ";
                    tmp = inv(s, n) * (i + 1) % n;
                    s = s * tmp % n;
                }
                cout << n << "\n";
            }
            else {
                cout << 0 << "\n";
            }
        }
    }
    return 0;
}

