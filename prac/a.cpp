/*************************************************************************
	> File Name: a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu May 11 00:51:26 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<string> s(n + 1);
        for (int i = 1; i <= n; i++) cin >> s[i];
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 1; j <= n; j++) {
                if (cnt == 0 and s[j][i] == 'v') {
                    cnt++;
                    break;
                }
                else if (cnt == 1 and s[j][i] == 'i') {
                    cnt++;
                    break;
                }
                else if (cnt == 2 and s[j][i] == 'k') {
                    cnt++;
                    break;
                }
                else if (cnt == 3 and s[j][i] == 'a') {
                    cnt++;
                    break;
                }

            }
        }
        if (cnt == 4) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

