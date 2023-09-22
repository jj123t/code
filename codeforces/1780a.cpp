/*************************************************************************
	> File Name: 1780a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul  6 19:36:57 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
    int n; cin >> n;
    using P = pair<int, int> ;
    vector<P> odd, even;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x & 1) odd.push_back({x, i + 1});
        else even.push_back({x, i + 1});
    }
    if (!odd.size() or (n == 3 and odd.size() == 2)) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        if (odd.size() >= 3) {
            for (int i = 0; i < 3; i++) {
                cout << odd[i].second <<  " ";
            }
        }
        else {
            cout << odd[0].second << " ";
            for (int i = 0; i < 2; i++) {
                cout << even[i].second << " ";
            }
        }
        cout << "\n";
    }
    }
    return 0;
}

