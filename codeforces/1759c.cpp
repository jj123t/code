/*************************************************************************
	> File Name: 1759c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jun 25 05:38:38 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int l, r, x; cin >> l >> r >> x;
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        if (a == b) cout << 0 << '\n';
        else if (b - a >= x) cout << 1 << "\n";
        else if (a - l >= x and l + x <= b) {
            cout << 2 << "\n";
        }
        else if (a + x <= r and r - x >= b) {
            cout << 2 << "\n";
        }
        else if (a + x <= r and r - l >= x and  l + x <= b) {
            cout << 3 << "\n";
        }
        else if (a - x >= l and l + x <= r and r - x >= b) {
            cout << 3 << "\n";
        }
        else cout << -1 << "\n";
    }
    return 0;
}

