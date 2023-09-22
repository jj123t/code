/*************************************************************************
	> File Name: 1742b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jun 23 03:23:53 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int tt; cin >> tt;
    while (tt--) {
        set<int> st;
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            st.insert(x);
        }
        if (st.size() == n) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

