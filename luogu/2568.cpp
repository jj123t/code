/*************************************************************************
	> File Name: 2568.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Aug  1 19:31:52 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    // sigmal p : primes, sigmal i : [1, n / p], sigmal j : [1, n / p] [gcd(i, j) == 1]
    // sigmal p : primes, sigmal i : [1, n / p], 2 * sigmal j : [1, i] [gcd(i, j) == 1]
    // sigmal p : primes, sigmal i : [1, n / p], 2 * phi(i) - 1
    int n; cin >> n;
    vector<int> phi(n + 1);
    phi[1] = 1;
    vector<int> prime;
    vector<int> vis(n + 1);
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) prime.push_back(i), phi[i] = i - 1;
        for (auto p : prime) {
            if (p * i > n) break;
            vis[p * i] = true;
            if (i % p == 0) {
                phi[p * i] = phi[i] * p;
                break;
            }
            else {
                phi[p * i] = phi[i] * phi[p];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) phi[i] += phi[i - 1];
    for (auto x : prime) {
        ans += 2 * phi[n / x] - 1;
    }
    cout << ans << "\n";
    return 0;
}

