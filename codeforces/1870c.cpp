/*************************************************************************
	> File Name: 1870c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Sep 18 22:30:26 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)  cin >> a[i];
        set<int> st;
        for (int i = 1; i <= n; i++) st.insert(a[i]);
        int left = 1, right = n;
        vector<int> ans(k + 1);
        for (int i = 1; i <= k; i++) {
            if (!st.count(i)) ans[i] = 0;
            else {
                while (left <= n and a[left] < i) left++;
                while (right >= 1 and a[right] < i) right--;
                if (right >= left) ans[i] = 2 * (right - left + 1);
            }
        }
        for (int i = 1; i <= k; i++) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}

