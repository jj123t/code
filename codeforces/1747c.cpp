/*************************************************************************
	> File Name: 1747c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jun 24 21:23:41 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int mx = 1e9, first = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (i == 0) first = x;
            mx = min(mx, x);
        }
        if (mx == first) cout << "Bob\n";
        else cout << "Alice\n" ;
    }
    return 0;
}

