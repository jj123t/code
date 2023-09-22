/*************************************************************************
	> File Name: 1747b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jun 24 21:07:37 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int a = 2, b = 6;
        cout << n / 2 + (n & 1) << "\n"; 
        for (int i = 0; i < (n + 1) / 2; i++) {
            cout << 1 + (3 * i) << " " << 3 * n - (3 * i) << "\n";
        }
    }
    return 0;
}

