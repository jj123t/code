/*************************************************************************
	> File Name: test.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed 12 Apr 2023 01:46:17 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int x = (1 << 15) - 1;
    for (int i = 0; i < 15; i++) {
        int y = x;
        y &= ~(1 << i);
        for (int j = 0; j < 15; j++) {
            cout << (y >> j & 1) ;
        }
        cout << "\n";
    }
    return 0;
}
