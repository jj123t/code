/*************************************************************************
	> File Name: 1793c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com > Created Time: Tue Jul 11 14:46:15 2023 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        set<int> st;
        for (int i = 0; i < n; i++) st.insert(arr[i]);
        int l = 0, r = n - 1;
        while (l < r and st.size()) {
            int L = l, R = r;
            if (!st.empty() and *(--st.end()) == arr[l]) {
                st.erase(--st.end());
                l++;
            }
            if (!st.empty() and *(st.begin()) == arr[l]) {
                st.erase(st.begin());
                l++;
            }
            if (!st.empty() and *(--st.end()) == arr[r]) {
                st.erase(--st.end());
                r--;
            }
            if (!st.empty() and *(st.begin()) == arr[r]) {
                st.erase(st.begin());
                r--;
            }
            if (l == L and r == R) break;
        }
        if (st.empty() or l >= r) cout << -1 << '\n'; 
        else cout << l + 1 << " " << r + 1 << "\n";
    }
    return 0;
}

