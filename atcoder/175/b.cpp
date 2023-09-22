/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jun  1 04:31:44 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    int ans = 0;
    for (int i = 0; i < n; i++) { 
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] != arr[j] && arr[i] != arr[k] && arr[j] != arr[k] && arr[k] < arr[i] + arr[j]) {
                    ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}

