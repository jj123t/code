/*************************************************************************
	> File Name: 1857a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Aug  7 22:18:44 2023
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
        int odd = 0, even = 0;
        for (int i = 1; i <= n; i++) {
            if (arr[i] & 1) odd++;
            else even++;
        }
        if (odd & 1) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
    return 0;
}

