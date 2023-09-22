/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue 02 May 2023 02:31:58 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n, d; cin >> n >> d;
    int ans = 0;
    vector<vector<int>> a(n, vector<int>(d, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) cin >> a[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (k == i) continue;
            int x = 0;
            for (int j = 0; j < d; j++) {
                x += (int)pow((a[i][j] - a[k][j]), 2);
            }
            int t = sqrt(x);
            if (t * t == x) ans++;
        }
    }
    cout << ans / 2;
    return 0;
}
