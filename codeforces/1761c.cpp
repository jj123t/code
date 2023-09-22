/*************************************************************************
	> File Name: test.cpp
	> Author:123emm
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jun 24 19:50:00 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<string> s(n);
        for (auto &x : s) cin >> x;
        bitset<110> bt[n];
        for (int i = 0; i < n; i++) {
            bt[i][i] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i][j] == '1') bt[j] |= bt[i];
            }
        }
        for (int i = 0; i < n; i++) {
            cout << bt[i].count() << " ";
            for (int j = 0; j < n; j++) {
                if (bt[i][j] == 1) {
                    cout << j + 1 << " ";
                }
            }
            cout << "\n";
        }
    }
  return 0;
}


