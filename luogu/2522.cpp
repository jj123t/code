/*************************************************************************
	> File Name: 2522.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Aug 18 16:07:26 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
vector<int> miu(1000100, 0);
void init(int n) {
    miu[1] = 1;
    for (int i = 1; i < n / 2; i++) {
        if (miu[i] != 0) {
            for (int j = 2 * i; j <= n; j += i) {
                miu[j] -= miu[i];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        miu[i] += miu[i - 1];
    }
}
int solve(int n, int m) {
    int res = 0;
    for (int l = 1, r = 0; l <= min(n, m); l = r + 1) {
        r = min(n / (n / l), m / (m / l));
        res += (miu[r] - miu[l - 1]) * (n / l) * (m / l);
    }
    return res;
}
int main()
{
    init(1e6 + 10);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b, c, d, k; cin >> a >> b >> c >> d >> k;
        cout << solve(b / k, d / k) - solve(b / k, (c - 1) / k) - solve((a - 1) / k, d / k) + solve((a - 1) / k, (c - 1) / k) << "\n";
    }
    return 0;
}

