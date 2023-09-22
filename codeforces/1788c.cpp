/*************************************************************************
	> File Name: 1788c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul 11 20:23:58 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        if (n == 1) {
            cout << "YES\n" << 1 << " " << 2 << "\n";
            continue;
        }
        using P = pair<int, int> ;
        vector<P> ans;
        int t = 2 * n + 1;
        for (int i = 1, j = 0; j <= (n - 1) / 2; i += 2, j++) {
            ans.push_back({i, t - i});
            t++;
        }
        t = 2 * n - (n - 1) / 2 + 1;
        for (int i = 2, j = 0; j < (n - 1) / 2; i += 2, j++) {
            ans.push_back({i, t - i});
            t++;
        }
        if (n %  2 == 0) cout << "NO\n";
        else {
            cout << "YES\n";
            for (auto [x, y] : ans) {
                cout <<x << " " << y << "\n";
            }
        }
    }
    return 0;
}

