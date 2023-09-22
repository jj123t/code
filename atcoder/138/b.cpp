/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue 02 May 2023 02:07:56 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define db long double
int main () {
    int n; cin >> n;
    vector<db> arr(n);
    db ans = 0.0;
    for (auto &a : arr) {
        cin >> a;
        ans += 1.0 / a;
    }
    cout << setprecision(20) << fixed << (1.0 / ans);
    return 0;
}
