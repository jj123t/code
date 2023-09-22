/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon 17 Apr 2023 11:59:38 AM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
int gcd(int a, int b) { return __gcd(a, b); }
int lcm(int a, int b) { return a * b / __gcd(a, b); }
signed main () {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &a : arr) cin >> a;
    int GCD = arr[0];
    bool flag = true;
    const int N = 1e6 + 10;
    vector<int> cnt(N, 0);
    for (int i = 0; i < n; i++) {
        GCD = gcd(arr[i], GCD);
        cnt[arr[i]]++;
    }
    for (int i = 2; i < N; i++) {
        int tmp = 0;
        for (int j = i; j < N; j += i) {
            tmp += cnt[j];
        }
        if (tmp > 1) flag = false;
    }
    if (flag) {
        cout << "pairwise coprime";
    }
    else {
        if (GCD == 1) cout << "setwise coprime";
        else cout << "not coprime";
    }
    return 0;
}
