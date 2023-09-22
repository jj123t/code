/*************************************************************************
	> File Name: 1759b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jun 25 05:32:32 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> arr(100000, 0);
        int mx = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            arr[x]++;
            mx = max(mx, x);
        }
        for (int i = 0; i <= mx; i++) {
            if (arr[i] == 0) {
                k -= i;
            }
        }
        if (k < 0) {
            cout << "NO\n";
            continue;
        }
        int idx = mx + 1;
        while (k > 0) {
            k -= idx++;
        }
        if (k == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

