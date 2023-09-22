/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun 16 Apr 2023 10:24:50 AM CST
 ************************************************************************/
#include <atcoder/all>
#include<bits/stdc++.h>
using namespace std;
using namespace atcoder;
typedef long long ll;
using mint2 = modint1000000007;
int main() {
    ll nn, k; cin >> nn >> k;
    vector<ll> neg, nneg;
    for (int i = 0; i < nn; i++) {
        ll x; cin >> x;
        if (x < 0) neg.push_back(x);
        else nneg.push_back(x);
    }
    int n = nneg.size(), m = neg.size();
    mint2 ans = 1;
    sort(neg.begin(), neg.end());
    sort(nneg.begin(), nneg.end());
    if (nn == k) {
        for (auto a : neg) {
            ans *= a;
        }
        for (auto b : nneg) {
            ans *= b;
        }
        cout << ans.val();
        return 0;
    }
    if (nneg.size() == nn) {
        for (int i = 0; i < k; i++) {
            ans *= nneg[n - 1 - i];
        }
        cout << ans.val();
        return 0;
    }
    if (neg.size() == nn) {
        if (k % 2 == 0) {
            for (int i = 0; i < k; i++) {
                ans *= neg[i];
            }
        }
        else {
            for (int i = 0; i < k; i++) {
                ans *= neg[m - 1 - i];
            }
        }
        cout << ans.val();
        return 0;
    }
    reverse(nneg.begin(), nneg.end());
    ll left = 0, right = 0;
    if (k % 2 == 1) {
        k--;
        ans *= nneg[0];
        left++;
    }
    while (k) {
        ll a = 0, b = 0;
        if (left + 1 < n) {
            a = nneg[left] * nneg[left + 1];
        }
        if (right + 1 < m) {
            b = neg[right] * neg[right + 1];
        }
        if (a >= b) {
            ans *= a % 1000000007;
            left += 2;
            k -= 2;
        }
        else {
            ans *= b % 1000000007;
            right += 2;
            k -= 2;
        }
    }
    cout << ans.val();
    return 0;
}

