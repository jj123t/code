/*************************************************************************
	> File Name: 1783a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jun 29 16:19:17 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        sort(arr.begin() + 1, arr.end(), [&](int a, int b){
             return a > b;
             });
        bool flag = true;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (arr[i] == 0) flag = false;
            }
            else {
                if (arr[i] == sum) flag = false;
            }
            sum += arr[i];
        }
        if (flag) {
            cout << "YES\n";
            for (auto x : arr) cout << x << " ";
            cout << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}

