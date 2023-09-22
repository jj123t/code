/*************************************************************************
	> File Name: c.cpp
	> Author: abcemm
	> Mail: 2542142016@qq.com 
	> Created Time: Sat May  6 05:36:49 2023
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main() {
	int n; cin >> n;
	string s = "";
	while (n) {
		if (n & 1) s += "A", n--;
		else s += "B", n /= 2;
	}
	reverse(s.begin(), s.end());
	cout << s;
    return 0;
}

