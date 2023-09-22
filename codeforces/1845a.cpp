/*************************************************************************
	> File Name: 1845a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jun 29 22:09:34 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, k, x; cin >> n >> k >> x;
        if (x != 1) {
            cout << "YES\n";
            cout << n << "\n";
            for (int i = 0; i < n; i++) {
                cout << 1 <<" " ;
            }
            cout << "\n";
        }
        else {
            if (k > n) {
                cout << "YES\n";
                cout << 1 << "\n";
                cout << n << "\n";
            }
            else {
                if (k == 1) {
                    cout << "NO\n";
                }
                else if (k == 2) {
                    if (n % 2 == 0) {
                        cout << "YES\n";
                        cout << n / 2 << "\n";
                        while (n) {
                            cout << 2 << " ";
                            n -= 2;
                        }
                        cout << "\n";
                    }
                    else {
                        cout << "NO\n";
                    }
                }
                else {
                    cout << "YES\n";
                    if (n % 2 == 0) {
                        cout << n / 2 << "\n";
                        for (int i = 0; i < n / 2; i++) {
                            cout << 2 << " ";
                        }
                        cout<< "\n";
                    }
                    else {
                        cout << n / 2 << "\n";
                        for (int i = 0; i < n / 2 - 1; i++) {
                            cout << 2 << " ";
                        }
                        cout << 3 << "\n";
                    }
                }
            }
        }
    }
    return 0;
}

