/*************************************************************************
	> File Name: 1855a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 29 21:48:53 2023
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
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (arr[i] == i) ans++;
        }
        cout << (ans + 1) / 2 << "\n";
    }
    return 0;
}

