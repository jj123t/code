/*************************************************************************
	> File Name: 183c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jul 23 22:25:44 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    vector<int> st;
    st.push_back(0);
    for (int i = 1; i <= 100000; i++) st.push_back(i);
    int m = 9;
    int t[m] = {1, 4, 7, 9, 12, 15, 17, 18, 20};
    int i = 0;
    int cnt = 10;
    while (cnt--) {
        for (int i  =0; i < m; i++) {
            cout << st[t[i]] << " ";
        }
        for (int i = m - 1; i > -1; i--) {
            st.erase(st.begin() + t[i]);
        }
        cout <<"\n";            
    }
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) cin >> arr[i];
        int ans = 0;
        if (arr[1] != 1) ans = 1;
        else {
        }
        cout << ans << "\n";
    }
    return 0;
}

