/*************************************************************************
	> File Name: 1767a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul  3 20:31:47 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int x1, y1, x2, y2, x3, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3; 
        int a1 = min(x1, x2), a2 = min(x1, x3), a3 = min(x2, x3);
        int aa1 = max(x1, x2), aa2 = max(x1, x3), aa3 = max(x2, x3);
        int b1 = min(y1, y2), b2 = min(y1, y3), b3 = min(y2, y3);
        int bb1 = max(y1, y2), bb2 = max(y1, y3), bb3 = max(y2, y3);
        bool flag = false;
        if ((a1 < x3 and x3 < aa1) || (a2 < x2 and x2 < aa2) || (a3 < x1 and x1 < aa3)) {
            flag = true;
        }
        if ((b1 < y3 and y3 < bb1) || (b2 < y2 and y2 < bb2) || (b3 < y1 and y1 < bb3)) {
            flag = true;
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

