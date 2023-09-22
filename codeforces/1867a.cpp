/*************************************************************************
	> File Name: 1867a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Sep 11 22:08:59 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        using P = pair<int, int>;
        vector<P> arr(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i].first;
            arr[i].second = i;
        }
        sort(arr.begin() + 1, arr.end());
        vector<int> brr(n + 1);
        int r = n;
        for (int i = 1; i <= n; i++) {
            brr[arr[i].second] = r--;
        }
        for (int i = 1; i <= n; i++) {
            cout << brr[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}

