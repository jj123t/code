/*************************************************************************
	> File Name: 2485.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Aug  2 17:33:01 2023
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
int BSGS(int a, int b, int m) { // a^x = b (mod m)
    unordered_map<int, int> hs;
    hs.clear();
    int cur = 1, t = sqrt(m) + 1;
    for (int B = 1; B <= t; B++) {
        cur = (cur * a) % m;
        hs[b * cur % m] = B;
    }
    int now = cur;
    for (int A = 1; A <= t; A++) {
        auto it = hs.find(now);
        if (it != hs.end()) return A * t - it->second;
        now = (now * cur) % m;
    }
    return -1;
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
    int tt; cin >> tt;
    int k; cin >> k;
    while (tt--) {
        int y, z, p; cin >> y >> z >> p;
        if (k == 1) {
            cout << mypow(y, z, p) << "\n";
        }
        else if (k == 2) {
            int a, b; int d = extgcd(a, b, y, p);
            if (z % d != 0) {
                cout << "Orz, I cannot find x!\n";
            }
            else {
                int t = p / d;
                while (a < 0) a += t;
                cout << ((a * z / d % t) + t) % t << "\n";
            }
        }
        else {
            if (!(y % p)) {
                if (z % p) {
                    cout << "Orz, I cannot find x!\n";
                }
                else {
                    cout << 1 << "\n";
                }
                continue;
            }
            int t = BSGS(y, z, p);
            if (y % p == 0 or t == -1) {
                cout << "Orz, I cannot find x!\n";
            }
            else cout << t << "\n";
        }
    }
    return 0;
}

