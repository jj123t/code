/*************************************************************************
	> File Name: cf776b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Aug  3 15:16:50 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<int> vis(1000100);
    for (int i = 2; i <= 1000000; i++) {
        if (vis[i]) continue;
        for (int j = 2 * i; j <= 1000000; j += i) {
            vis[j] = true;
        }
    }
    set<int> st;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (!vis[i + 2]) ans[i] = 1, st.insert(1); 
        else ans[i] = 2, st.insert(2);
    }
    cout << st.size() << "\n";
    for (auto x : ans) cout << x << " ";
    return 0;
}

