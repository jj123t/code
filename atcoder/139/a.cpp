/*************************************************************************
	> File Name: a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue 02 May 2023 01:51:18 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    string a, b; cin >> a >> b;
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) ans++;
    }
    cout << ans;
    return 0;
}
