/*************************************************************************
	> File Name: 1809c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul 12 20:41:32 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        int i = 0;
        while ((i + 2) * (i + 1) / 2 <= k) {
            i++;
        }
        int d = k - (i) * (i + 1) / 2;
        vector<int> ans;
        for (int j = 0; j < i; j++) ans.push_back(1);
        if (d) ans[d - 1] = 1000;
        ans.push_back(-500);
        for (int j = i + 1; j < n; j++) {
            ans.push_back(-1000);
        }
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}

