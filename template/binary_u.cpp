/*************************************************************************
	> File Name: binary_u.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri May 19 22:01:11 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int lb = -1, ub = n;
    while (ub - lb > 1) {
        int mid = (lb + ub) >> 1;
        if (check(mid)) ub = mid;
        else lb = mid;
    }
    cout << ub;
    return 0;
}

