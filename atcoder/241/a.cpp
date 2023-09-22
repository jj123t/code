/*************************************************************************
	> File Name: a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed May 31 01:04:56 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int tmp = 0;
    vector<int> arr(10);
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < 3; i++) {
        tmp = arr[tmp];
    }
    cout << tmp;
    return 0;
}

