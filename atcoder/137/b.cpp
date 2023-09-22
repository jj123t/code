/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue 02 May 2023 02:12:52 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n, x; cin >> n >> x;
    for (int i = x - n + 1; i < x + n; i++) {
        cout << i << " ";
    }
    return 0;
}
