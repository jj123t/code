/*************************************************************************
	> File Name: a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon 01 May 2023 03:13:17 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    if (k < n) {
        for (int i = k; i < n; i++) cout << arr[i] << " "; 
        for (int i = 0; i < k; i++) cout << 0 << " ";
    }
    else {
        for (int i = 0; i < n; i++) {
            cout << 0 << " ";
        }
    }
    return 0;
}
