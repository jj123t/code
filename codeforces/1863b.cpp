/*************************************************************************
	> File Name: 1863b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Aug 30 21:27:09 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, a, q; cin >> n >> a >> q;
        string s; cin >> s;
        int res = a;
        bool flag = false;
        int b = 0;
        for (int i = 0; i < q + 1; i++) {
            if (res == n) {
                flag = true;
            }
            if (i == q) break;
            if (s[i] == '-')  res--;
            else b++, res++;
        }
        if (flag) cout << "YES\n";
        else if (b < n - a) cout << "NO\n";
        else cout << "MAYBE\n";
    }
    return 0;
}

