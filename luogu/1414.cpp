/*************************************************************************
	> File Name: 1414.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Aug  1 23:19:28 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int cnt[1001000];
int main()
{
    int n; cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        mx = max(x, mx);
        for (int j = 1; j * j <= x; j++) {
            if (x % j == 0) {
                cnt[j]++;
                if (x / j != j) cnt[x / j]++;
            }
        }
    }
    int r = mx;
    for (int i = 1; i <= n; i++) {
        while (cnt[r] < i) r--;
        cout << r << "\n";
    }
    return 0;
}

