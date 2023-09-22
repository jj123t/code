/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jun 28 15:13:35 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<char> a(3), b(3);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    int res = 0;
    for (int i = 0; i < 3; i++) {
        if (a[i] == b[i]) res++;
    }
    if (res == 1) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}

