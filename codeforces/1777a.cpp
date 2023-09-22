/*************************************************************************
	> File Name: 1777a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul 12 13:31:41 2023
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
        int last = arr[0] & 1;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int a = arr[i] & 1;
            if (a == last) {
                ans++;
                if (a & 1) last = 1;
                else last = 0;
            }
            last = a;
        }
        cout << ans << "\n";
    }
    return 0;
}

