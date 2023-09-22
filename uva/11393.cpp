/*************************************************************************
	> File Name: 11393.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Sep 19 11:31:06 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    while (n != 0) {
        int cnt = n * (n - 1) / 2;
        if (n == 1 or (n % 3 == 2)) cout << "NO\n";
        else cout << "YES\n";
        cin >> n;
    }
    return 0;
}

