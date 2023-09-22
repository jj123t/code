/*************************************************************************
	> File Name: 1782b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul  5 11:54:53 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n + 1);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            arr[x]++;
        }
        int ans = 0;
        int tmp = 0;
        for (int i = 0; i <= n; i++) {
            if (i) tmp += arr[i - 1];
            if (i == n || !arr[i] && i == tmp) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

