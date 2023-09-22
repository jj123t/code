/*************************************************************************
	> File Name: 1290.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Aug  4 15:03:21 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        int flag = 0;
        int t = 0;
        while (x and y) {
            flag++;
            if (x > y) {
                if (x / y > 1 and t == 0) t = flag;
                x = x % y;
            }
            else {
                if (y / x > 1 and t == 0) t = flag;
                y = y % x;
            }
        }
        if ((t & 1) or (t == 0 and flag % 2 == 1)) {
            cout << "Stan wins" << "\n";
        }
        else {
            cout << "Ollie wins" << "\n";
        }
    }
    return 0;
}

