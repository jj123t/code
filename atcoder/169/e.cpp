/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri 14 Apr 2023 04:50:22 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n; cin >> n;
    vector<int> arr(n), brr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i] >> brr[i];
    }
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
    if (n & 1) {
        cout << brr[n / 2]  - arr[n / 2] + 1;
    }
    else {
        int y = brr[n / 2 - 1] + brr[n / 2];
        int x = arr[n / 2 - 1] + arr[n / 2];
        cout << y - x + 1; 
    }
    return 0;
}
