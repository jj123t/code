/*************************************************************************
	> File Name: 1863a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Aug 30 21:26:58 2023
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
        vector<int> id(n + 1);
        for (int i = 1; i <= n; i++) id[arr[i]] = i;
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            if (arr[i] != i) {
                flag = true;
            }
        }
        if (flag) {
            cout << 0 << "\n";
            continue;
        }
        int st = 1;
        int idx = id[st];
        int ans = 1;
        st++;
        while (st != n) {
            while (st < n and id[st] > idx) {
                idx = id[st];
                st++;
            }
            if (st < n) {
                ans++;
                idx = id[st];
                st++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

