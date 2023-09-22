/*************************************************************************
	> File Name: 11850.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Sep 16 22:24:35 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    while (n != 0) {
        vector<int> idx(n + 1);
        for (int i = 0; i < n; i++) cin >> idx[i];
        idx[n] = 1422;
        sort(idx.begin(), idx.end());
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            if (idx[i] - idx[i - 1] > 200) {
                ok = false;
            } 
        }
        if (idx[n] - idx[n - 1] > 100) ok = false;
        if (ok) cout << "POSSIBLE\n";
        else cout << "IMPOSSIBLE\n";
        cin >> n;
    }
    return 0;
}

