/*************************************************************************
	> File Name: test.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Aug 30 15:26:31 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
#define int long long 
signed main()
{
    int n; cin >> n;
    vector<int> phi(N);
    iota(phi.begin(), phi.end(), 0);
    for (int i = 2; i < N; i++) {
        if (phi[i] == i) {
            for (int j = i; j < N; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
    vector<int> ans(N), a(N);
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                a[i] += ((i - 1) / j) * phi[j];
            }
        }
    }
    for (int i = 1; i < N; i++) {
        ans[i] = ans[i - 1] + a[i];
    }
    while (n != 0) {
        cout << ans[n] << "\n";
        cin >> n;
    }
    return 0;
}


