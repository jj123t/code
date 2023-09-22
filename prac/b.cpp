/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu May 11 01:03:21 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) cin >> arr[i];
        vector<int> b;
        for (int i = 1; i <= n; i++) {
            if (arr[i] >= arr[i - 1]) {
                b.push_back(arr[i]);
            }
            else {
                b.push_back(arr[i]);
                b.push_back(arr[i]);
            }
        }
        cout << b.size() << "\n";
        for (auto x : b) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
