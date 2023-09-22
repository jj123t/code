/*************************************************************************
	> File Name: 1846c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul  7 22:28:32 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, m, h; cin >> n >> m >> h;
        vector<vector<int>> arr(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            sort(arr[i].begin(), arr[i].end());
        }
        vector<array<int, 3>> brr;
        for (int i = 0; i < n; i++) {
            int res = h;
            int t = 0;
            int j = 0;
            int s = 0;
            for (j = 0; j < m; j++) {
                if (res < arr[i][j]) break;
                s += arr[i][j];
                t += s;
                res -= arr[i][j];
            }
            brr.push_back({j + 1, t, i + 1});
        }
        sort(brr.begin(), brr.end(), [&](array<int, 3> a, array<int, 3> b){
             if (a[0] == b[0]) {
             if (a[1] == b[1]) return a[2] < b[2];
             else return a[1] < b[1];
             }
             else return a[0] > b[0];
             });
        /*
        for (int  i =0; i< n; i++) {
            for (auto x : brr[i]) {
                cout << x << " ";
            }
            cout << "\n";
        }
        */
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (brr[i][2] == 1) {
                ans = i + 1;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

