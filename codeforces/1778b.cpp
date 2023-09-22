/*************************************************************************
	> File Name: 1778b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 14 20:48:17 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, m, d; cin >> n >> m >> d;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            p[x] = i;
        }
        vector<int> arr(m);
        int ans = 1e9;
        for (int i = 0; i < m; i++) cin >> arr[i];
        bool flag = true;
        for (int i = 1; i < m; i++) {
            int x = arr[i];
            int y = arr[i - 1];
            if (p[x] > p[y] and p[y] + d >= p[x]) {
                ans = min(ans, p[x] - p[y]);
                if (d + 2 <= n) ans = min(ans, d - (p[x] - p[y]) + 1);
            }
            else {
                flag = false;
            }
        }
        if (!flag) cout << 0 << "\n";
        else cout << ans << "\n";
    }
    return 0;
}

