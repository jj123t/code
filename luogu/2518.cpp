/*************************************************************************
	> File Name: 2518.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Aug 10 09:03:44 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    string s; cin >> s;
    int n = s.size();
    vector<int> cnt(10, 0);
    vector<vector<int>> C(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; i++) cnt[s[i] - '0']++;
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    auto Choose = [&](int x) -> int {
        int t = 1;
        for (int i = 0; i <= 9; i++) {
            t *= C[x][cnt[i]];
            x -= cnt[i];
        }
        return t;
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[i] - '0'; j++) {
            if (cnt[j]) {
                cnt[j]--;
                ans += Choose(n - (i + 1));
                cnt[j]++;
            }
        }
        cnt[s[i] - '0']--;
    }
    cout << ans << "\n";
    return 0;
}

