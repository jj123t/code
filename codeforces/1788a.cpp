/*************************************************************************
	> File Name: 1788a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul 11 19:55:48 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n);
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] == 1) a++;
            else b++;
        }
        int ta = 0, tb = 0;
        int c = -2;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) ta++;
            else tb++;
            if (tb * 2 == b) {
                c = i;
                break;
            }
        }
        cout << c + 1 << "\n";
    }
    return 0;
}

