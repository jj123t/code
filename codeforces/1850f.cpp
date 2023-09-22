/*************************************************************************
	> File Name: 1850f.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 21 23:41:32 2023
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
        vector<int> cnt(n + 1);
        int lazy = 0;
        for (int i = 1; i <= n; i++) {
            if (arr[i] == 1) {
                lazy++;
                continue;
            }
            for (int j = arr[i]; j <= n; j += arr[i]) {
                cnt[j]++;
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            cnt[i] += lazy;
            if (cnt[i] > res) {
                res = cnt[i];
            }
        }
        cout << res << "\n";
    }
    return 0;
}

