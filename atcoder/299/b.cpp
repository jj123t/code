/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat 22 Apr 2023 07:52:25 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n, k; cin >> n >> k;
    map<int, int> mp;
    map<int, int> mp2;
    map<int, int> idx;
    vector<int> c(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        mp[c[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> r[i];
        if (r[i] > mp2[c[i]]) {
            mp2[c[i]] = r[i];
            idx[c[i]] = i + 1;
        }
    }
    if (mp[k]) {
        cout << idx[k];
    }
    else {
        int col = c[0];
        cout << idx[col];
    }
    return 0;
}
