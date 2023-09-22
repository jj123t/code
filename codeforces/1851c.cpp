/*************************************************************************
	> File Name: 1851c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul 25 22:20:18 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) cin >> arr[i];
        vector<int> pfx(n + 1), sufx(n + 2);
        for (int i = 1; i <= n; i++) {
            pfx[i] = pfx[i - 1] + (arr[i] == arr[1]);
        }
        for (int i = n; i >= 1; i--) {
            sufx[i] = sufx[i + 1] + (arr[i] == arr[n]);
        }
        bool flag = false;
        if (arr[1] == arr[n]) {
            if (pfx[n] >= k) flag = true;
        }
        for (int i = 1; i <= n; i++) {
            if (pfx[i] >= k and sufx[i] >= k) {
                flag = true;
            }
        }
        if (flag) cout << "YEs\n";
        else cout << "No\n";
    }
    return 0;
}

