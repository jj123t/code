/*************************************************************************
	> File Name: 1794b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul  5 22:14:22 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        if (arr[0] == 1) arr[0]++;
        for (int i = 1; i < n; i++) {
            if (arr[i] == 1) arr[i]++;
            if (arr[i] % arr[i - 1] == 0) {
                arr[i]++;
            }
        }
        for (auto x : arr) cout << x << " ";
        cout << '\n';
    }
    return 0;
}

