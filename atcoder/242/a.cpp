/*************************************************************************
	> File Name: a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jun 30 13:06:13 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, d; cin >> a >> b >> c >> d;
    cout << setprecision(20) << fixed << "\n";
    if (d <= a) cout << 1;
    else if (d > b) cout << 0;
    else {
        cout << (double)c / (b - a) ; 
    }
    return 0;
}

