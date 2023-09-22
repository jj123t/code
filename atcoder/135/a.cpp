/*************************************************************************
	> File Name: a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue 02 May 2023 02:24:52 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int a, b; cin >> a >> b;
    if ((b + a) & 1) cout << "IMPOSSIBLE";
    else cout << (b + a) / 2 ;
    return 0;
}
