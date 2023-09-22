/*************************************************************************
	> File Name: a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jun  1 04:27:13 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    string s; cin >> s;
    int tmp = (s[0] == 'R');
    int ans = tmp;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == 'S') tmp = 0;
        else tmp++;
        ans = max(ans, tmp);
    }
    cout << ans;
    return 0;
}

