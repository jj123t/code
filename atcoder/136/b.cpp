/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue 02 May 2023 02:15:34 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        bool flag = true;
        string s = to_string(i);
        ans += (int(s.size())) & 1;
    }
    cout << ans;
    return 0;
}
