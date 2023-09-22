/*************************************************************************
	> File Name: 1767b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul  3 20:53:39 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n); 
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin() + 1, arr.end());
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[0]) {
                arr[0] += (arr[i] - arr[0] + 1) / 2;
            }
        }
        cout << arr[0] << "\n";
    }
    return 0;
}

