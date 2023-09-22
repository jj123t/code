/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed 12 Apr 2023 07:58:27 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n, k, c; cin >> n >> k >> c;
    string s; cin >> s;
    vector<int> pfx(k, 0), sfx(k, 0);
    int idx1 = 0, idx2 = k - 1;
    int last = -1e9;
    for (int i = 0; i < n && idx1 < k; i++) {
        if (s[i] == 'o' && i > last + c) {
            pfx[idx1++] = i;
            last = i;
        }
    }
    last = 1e9;
    for (int i = n - 1; i > -1, idx2 >= 0; i--) {
        if (s[i] == 'o' && i < last - c) {
            sfx[idx2--] = i;
            last = i;
        }
    }
    for (int i = 0; i < k; i++) {
        if (sfx[i] == pfx[i]) {
            cout << sfx[i] + 1 << "\n";
        }
    }
    return 0;
}
