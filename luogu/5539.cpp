/*************************************************************************
	> File Name: 5539.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Aug  1 12:05:44 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int extgcd(int &x, int &y, int a, int b) {
    if (!b) {
        x = 1, y = 0; 
        return a;
    }
    int d = extgcd(y, x, b, a % b);
    y -= a / b * x;
    return d;
}
int m[4], a[4] = {0, 0, 1, 2};
int n = 3;
int extcrt() {
    int A = a[1], M = m[1];
    for (int i = 2; i <= n; i++) {
        int d = gcd(M, m[i]);
        int rlc = M * m[i] / d;
        if ((a[i] - A) % d != 0) return -1;
        int t1, t2; extgcd(t1, t2, M / d, m[i] / d);
        int k1 = t1 * (a[i] - A) / d;
        A = ((A + k1 * M % rlc) + rlc) % rlc;
        M = rlc;
    }
    return A;
}
signed main()
{
    int N, M; cin >> N >> M; 
    vector<int> arr(M + 1);
    for (int i = 1; i <= M; i++) cin >> arr[i];
    int ans = 0;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= M; j++) {
            for (int k = 1; k <= M; k++) {
                if (i != j and j != k and k != i) {
                    m[1] = arr[i], m[2] = arr[j], m[3] = arr[k];
                    int rlc = lcm(m[1], lcm(m[2], m[3]));
                    int t = extcrt();
                    if (t != -1) {
                        if (t <= N) ans += N / 
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

