/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue 02 May 2023 01:46:24 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int a, b; cin >> a >> b;
    int ans = 0, r = 1;
    while (r < b) {
        r += a - 1;
        ans++;
    }
    cout << ans;
    return 0;
}
