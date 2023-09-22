/*************************************************************************
	> File Name: 1856b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Aug  5 22:00:31 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) cin >> arr[i];
        vector<int> brr(n + 1);
        if (n == 1) {
            cout << "No\n";
            continue;
        }
        bool ans = false;
        int res = 0;
        int t = 0;
        for (int i = 1; i <= n; i++) {
            if (arr[i] == 1) res++;
            else t += arr[i] - 1;
        }
        if (t >= res) ans = true;
        if (ans) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

