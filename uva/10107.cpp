/*************************************************************************
	> File Name: 10107.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Sep 16 19:31:29 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int num[1000100];
int main()
{
    int n = 0;
    while (scanf("%d", &num[++n]) != EOF) {
        sort(num + 1, num + n + 1);
        if (n & 1) cout << num[n / 2 + 1] << "\n";
        else cout << (num[n / 2] + num[n / 2 + 1]) / 2 << "\n";
    }
    return 0;
}

