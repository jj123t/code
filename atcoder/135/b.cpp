/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue 02 May 2023 02:22:01 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &c : arr) cin >> c;
    auto brr = arr;
    sort(brr.begin(), brr.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (brr[i] != arr[i]);
    }
    cout << (ans > 2 ? "NO" : "YES");
    return 0;
}
