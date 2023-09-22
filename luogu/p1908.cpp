/*************************************************************************
	> File Name: p1908.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue May 30 06:38:11 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
vector<int> tree(N);
int n;
void add(int i, int x) {
    while (i <= n) {
        tree[i] += x;
        i += (i & -i);
    }
}
long long qry(int i) {
    long long res = 0;
    while (i) {
        res += (long long)tree[i];
        i -= (i & -i);
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    cin >> n;
    vector<long long> arr(n); 
    for (auto &x : arr) cin >> x;
    auto brr = arr;
    sort(brr.begin(), brr.end());
    brr.erase(unique(brr.begin(), brr.end()), brr.end());
    for (auto &x : arr) x = lower_bound(brr.begin(), brr.end(), x) - brr.begin();
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int x = arr[i] + 1;
        add(x, 1);
        ans += i + 1 - qry(x);
    }
    cout << ans;
    return 0;
}

