/*************************************************************************
	> File Name: 1842b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jun 25 05:59:46 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, x; cin >> n >> x;
        vector<vector<int>> arr(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++) {
            cin >> arr[0][i];
        }
        for (int i = 0; i < n; i++) {
            cin >> arr[1][i];
        }
        for (int i = 0; i < n; i++) {
            cin >> arr[2][i];
        }
        vector<int> cnt(3, 0);
        vector<bool> F(3, false);
        int s = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                bool flag = true;
                if (cnt[j] >= n) continue;
                if (F[j]) continue;
                for (int k = 0; k < 30; k++) {
                    if ((arr[j][cnt[j]]) >> k & 1ll) {
                        if ((x >> k & 1ll) == 0) flag = false;
                    }
                }
                if (flag) {
                    for (int k = 0; k < 30; k++) {
                        if ((arr[j][cnt[j]]) >> k & 1ll) {
                            s |= (1ll << k);
                        }
                    }
                    cnt[j]++;
                }
                else F[j] = true;
            }
        }
        cout << (s == x ? "Yes\n" : "No\n");
    }
    return 0;
}

