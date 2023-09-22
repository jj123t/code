/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed 12 Apr 2023 09:39:01 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int h, w, K; cin >> h >> w >> K;
    vector<string> s(h);
    for (auto &a : s) cin >> a;
    int tmp = 0;
    int ans = 1e9;
    for (int i = 0; i < (1 << h); i++) {
        int res = 1 + __builtin_popcount(i);
        int tmp = res - 1;
        vector<int> cnt(res);
        bool flag = true;
        for (int j = 0;  j < w; j++) {
            int d = 0;
            for (int k = 0; k < h; k++) {
                if (s[k][j] == '1') cnt[d]++;
                if (i >> k & 1) {
                    d++;
                }
            }
            if (*max_element(cnt.begin(), cnt.end()) > K) {
                if (flag) {
                    tmp = 1e9;
                    break;
                }
                tmp++;
                for (auto &x : cnt) x = 0;
                j--;
                flag = true;
                continue;
            }
            flag = false;
        }
        ans = min(tmp, ans);
    }
    cout << ans;
    return 0;
}
