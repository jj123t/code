/*************************************************************************
  > File Name: 11387.cpp
  > Author:123emm 
  > Mail: 2542142016@qq.com
  > Created Time: Tue Sep 19 12:52:23 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    while (n != 0) {
        if ((n & 1) or (n < 3)) { cout << "Impossible\n"; }
        else {
            cout << n * 3 / 2 << "\n";
            vector<int> a(n + 1);
            for (int i = 1; i < n; i++) {
                cout << i << " " << i + 1 << "\n";
                if (!a[i]) {
                    a[i] = a[i + (n / 2)] = true;
                    cout << i << " " << i + n / 2 << "\n";
                }
            }
            cout << n << " " << 1 << "\n";
        }
        cin >> n;
    }
    return 0;
}

