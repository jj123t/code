/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue 25 Apr 2023 09:53:07 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n; cin >> n;
    using P = pair<int, int>;
    vector<P> ar(n);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        ar[i] = P(b, a);
    }
    sort(ar.begin(), ar.end());
    int tmp = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (ar[i].second >= tmp) {
            ans += ar[i].second - tmp;
            tmp = ar[i].second;
        }
        else {
            ans += tmp - ar[i].second;
            tmp = ar[i].second;
        }
    }
    cout << ans;
    return 0;
}
