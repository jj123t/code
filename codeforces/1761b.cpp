/*************************************************************************
	> File Name: 1761b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jun 25 22:00:10 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (auto &x : arr) cin >> x;
        bool flag = true;
        for (int i = 2; i < n; i++) {
            if (arr[i] != arr[i % 2]) {
                flag = false;
            }
        }
        if (flag) {
            cout << n / 2 + 1 << "\n";
        }
        else {
            cout << n << "\n";
        }
    }
    return 0;
}

