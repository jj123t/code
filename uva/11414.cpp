/*************************************************************************
	> File Name: 11414.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Sep 20 10:59:43 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        if (n == 0) {
            cout << "Yes\n";
            continue;
        }
        vector<int> d(n + 1);
        for (int i = 1; i <= n; i++) cin >> d[i];
        sort(d.begin() + 1, d.end(), [&](int a, int b) {
             return a > b;
             });
        vector<int> s(n + 1);
        bool flag = true;
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + d[i];
        if (s[n] % 2) {
            cout << "No\n";
            continue;
        }
        for (int i = 1; i <= n; i++) {
            int cnt = i * (i - 1);
            for (int j = i + 1; j <= n; j++) cnt += min(i, d[j]);
            if (s[i] > cnt) {
                flag = false;
            }
        }
        if (flag) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

