/*************************************************************************
	> File Name: 1868a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Sep 10 21:56:54 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n + 1); 
        for (int i = 1;  i<= n; i++) cin >> arr[i];
        bool flag = true;
        for (int i = 1; i <= n; i++) if (arr[i] != 0) flag = false;
        if (flag) {
            cout << 0 << '\n';
            continue;
        }
        int x = 0;
        for (int i = 1; i <= n; i++) x ^= arr[i];
        if (x == 0) {
            cout << 1 << '\n';
            cout << 1 << " " << n << '\n';
        }
        else {
            if (n & 1) {
                cout << 4 << '\n';
                cout << 1 << " " << n << "\n";
                cout << 1 << " " << 2 << '\n';
                cout << 2 << " " << 3 << "\n";
                cout << 2 << " " << n << "\n";
            }
            else {
                cout << 2 << '\n';
                cout << 1 << " " << n << '\n';
                cout << 1 << " " << n << '\n';
            }
        }
    }
    return 0;
}

