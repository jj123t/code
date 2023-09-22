/*************************************************************************
	> File Name: aa.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue May  9 06:29:55 2023
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
signed main () {
    while (true) {
        int op; cin >> op;
        if (op != 0) {
            vector<int> a(op), b(op);
            for (int i = 0; i < op; i++) cin >> a[i];
            for (int i = 0; i < op; i++) cin >> b[i];
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            int tmp = 0;
            int ans = 0;
            for (int i = 0; i < op; i++) {
                int x = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
                x--;
                tmp = max(tmp, x);
            }
            tmp++;
            cout << tmp * 200 + (op - tmp) * (-200);
        }
        else break;
    }
    return 0;
}
